# === Install package ===========
# > pip install pandas, aspose-cells
# > pip install openpyxl
# ===============================
# Import
import sys
import os
import pandas as pd
import xlsxwriter
import time

folder_iexcels = sys.argv[1]
folder_oexcels = sys.argv[2]

# === process ==========
def bar_process(i_process, max_process, title):
    if i_process <= max_process:
        print("%-1s (%d%-1s%d)" % (title, i_process, "/", max_process), end = "\r")
    if i_process == max_process:
        print("%-1s (%d%-1s%d)" % (title, i_process, "/", max_process))

# === move table to 0, 0 position in sheet =========
def fomart_table_ex(ipath_file_ex, opath_file_ex):

    xls = pd.ExcelFile(ipath_file_ex)
    sheets = xls.sheet_names

    workbook_output = xlsxwriter.Workbook(opath_file_ex)

    for sheet in sheets:
        df = pd.read_excel(xls, sheet)
        worksheet_output = workbook_output.add_worksheet(sheet)
        leng_row = len(df)
        leng_col = len(df.columns)

        w_row = 0
        w_col = 0
        selc_col = 0
        selc_row = 0

        for col in range(leng_col):
            if col >= selc_col:
                for row in range(leng_row):
                    if row >= selc_row:
                        value = str(df.iloc[row][col])
                        if value != "nan":
                            print(value)
                            worksheet_output.write(w_row, w_col, value)
                            w_row += 1
                w_col += 1
                w_row = 0

    workbook_output.close()

# === move table to 0, 0 position in sheet ===========
def fomart_table_exs(ifolder_ex, ffolder_ex):
    # === Get all file in folder
    all_excels = os.listdir(ifolder_ex)
    max_file = len(os.listdir(ifolder_ex))
    i_process = 0
    for file in all_excels:
        fomart_table_ex(ifolder_ex + file, ffolder_ex + file)

        i_process += 1
        bar_process(i_process, max_file, "Formarting file ...")

fomart_table_exs(folder_iexcels, folder_oexcels)