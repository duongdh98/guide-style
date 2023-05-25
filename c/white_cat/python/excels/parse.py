# === Install package ===========
# > pip install pandas, aspose-cells
# > pip install openpyxl
# ===============================
import sys
import os
import pandas as pd
import openpyxl
import xlsxwriter
import time

folder_fomart = sys.argv[1]
folder_output = sys.argv[2]

# === process ==========
def bar_process(i_process, max_process, title):
    if i_process <= max_process:
        print("%-1s (%d%-1s%d)" % (title, i_process, "/", max_process), end = "\r")
    if i_process == max_process:
        print("%-1s (%d%-1s%d)" % (title, i_process, "/", max_process))

def create_sheet_folder(iformart_ex, out_ex):
    path_sheets = out_ex + "sheets/"
    path_sheet = out_ex + "sheet/"
    path_csv = out_ex + "csv/"
    os.mkdir(path_sheets)
    os.mkdir(path_sheet)
    os.mkdir(path_csv)

    all_excels = os.listdir(iformart_ex)
    for file in all_excels:
        xls = pd.ExcelFile(iformart_ex + file)
        sheets = xls.sheet_names
        df = pd.read_excel(xls, sheets[0])

        for col in df.columns:
            value = str(col)
            path_item = path_sheets + value
            os.mkdir(path_item)
            os.mkdir(path_sheet + value)
            os.mkdir(path_csv + value)
        break

def parse_column(ipath, opath, name_col):

    xls = pd.ExcelFile(ipath)
    sheets = xls.sheet_names

    writer = pd.ExcelWriter(opath, engine='openpyxl') 
    for sheet in sheets:
        data = pd.read_excel(xls, sheet) 
        df_in = pd.DataFrame(data, columns=[name_col])
        wb  = writer.book
        df_in.to_excel(writer, sheet_name=sheet, index = False)
        wb.save(opath)

def convert_sheet(ipath, opath, name):
    xls = pd.ExcelFile(ipath)
    sheets = xls.sheet_names

    for sheet in sheets:
        data = pd.read_excel(xls, sheet) 
        df_in = pd.DataFrame(data)
        b_path = opath + sheet + "_" + name
        writer = pd.ExcelWriter(b_path, engine='openpyxl') 
        wb  = writer.book
        df_in.to_excel(writer, sheet_name=sheet, index = False)
        wb.save(b_path)

def convert_ex_from_exs(osheets, osheet):

    all_fol_sheets = os.listdir(osheets)
    for fol in all_fol_sheets:
        all_item = os.listdir(osheets + fol)
        i_p = 0
        max_pr = len(os.listdir(osheets + fol))

        for item in all_item:
            convert_sheet(osheets + fol + "/" + item, osheet + fol + "/", item)
            i_p += 1
            bar_process(i_p, max_pr, "Convert " + str(fol) + " to sheet ...")

def convert_to_csv(osheet, ocsv):
    all_fol_sheets = os.listdir(osheet)
    for fol in all_fol_sheets:
        all_item = os.listdir(osheet + fol)
        i_p = 0
        max_pr = len(os.listdir(osheet + fol))
        for item in all_item:
            ful_path = osheet + fol + "/" + item

            # === parse name ==========
            end_str = item.rfind(".")
            name_csv = item[:end_str]
            # =========================
            ful_path_csv = ocsv + fol + "/" + name_csv + ".csv"

            read_file = pd.read_excel(ful_path)
            read_file.to_csv (ful_path_csv, index = None, header= True)
            i_p += 1
            bar_process(i_p, max_pr, "Convert " + str(fol) + " to csv ...")

def parse_excel_sheets(iformart_ex, out_ex):
    # === Create folder ==================
    create_sheet_folder(iformart_ex, out_ex)

    all_excels_out =os.listdir(out_ex + "sheets/")
    all_excels_in = os.listdir(iformart_ex)

    # === parse excels ===================
    for fol in all_excels_out:
        path = out_ex + "sheets/" + fol
        i_p = 0
        max_pr = len(os.listdir(iformart_ex))

        for file_in in all_excels_in:
            parse_path = path + "/" + file_in
            parse_column(iformart_ex + file_in, parse_path, str(fol))

            i_p += 1
            bar_process(i_p, max_pr, "Parsing " + str(fol) + " column ...")

    # === converst sheets -> sheet ====
    convert_ex_from_exs(out_ex + "sheets/", out_ex + "sheet/")
    # === convert excel to csv =====
    convert_to_csv(out_ex + "sheet/", out_ex + "csv/")

parse_excel_sheets(folder_fomart, folder_output)