# _How To Convert Images Into ASCII Format In Linux_

This guide teaches how to convert images into ASCII format in Linux. For the purpose of this task, we will be using Jp2a. Jp2a is a command line tool that helps you to convert the given image(s) into ascii character format. You can specify a mixture of image files and URLs and the Jp2a tool will convert all of them into ascii characters instantly. Jp2a has many useful options to manipulate the images. Here are some couple things that Jp2a can do for you!

- read images from standard input,
- set background mode as light or dark,
- set border,
- set output height and width,
- set custom dimension for output images,
- flip output image vertically or horizontally,
- use a specific characters when producing the output ASCII image,
- invert images,
- download images from web and convert them,
- And many.

## 1. [Install Jp2a in Linux](#1)
## 2. [Convert Images Into ASCII Format In Linux](#2)
### 2.1 [Read images from standard input](#21)
### 2.2 [Write output to a file](#22)
### 2.3 [Print images with specific height/width](#23)
### 2.4 [Print images in ASCII format in X columns and Y rows](#24)
### 2.5 [Set border to ASCII characters](#25)
### 2.6 [Print images in light/dark background](#26)
### 2.7 [Print images into ASCII format in dark background](#27)
### 2.8 [Print images with specific characters only](#28)
### 2.9 [Download images directly from Internet](#29)
### 2.10 [Convert images other than JPG/JPEG](#210)
### 2.11 [Produce strict HTML output](#211)
### 2.12 [Help us to help you:](#212)

#

## <a id="1"></a> Install Jp2a in Linux

Jp2a is packaged for many Linux distributions and is available in the default repositories.

To install Jp2a on Arch Linux and its variants like Manjaro Linux, run:
```sh
  $ sudo pacman -S jp2a
```
On Debian, Ubuntu, Linux mint:
```sh
  $ sudo apt install jp2a
```
On Fedora:
```sh
  $ sudo dnf install jp2a
```
On CentOS / RHEL:
```sh
  $ sudo yum install epel-release
  $ sudo yum install jp2a
```
On openSUSE:
```sh
  $ sudo zypper install jp2a
```
## <a id="2"></a> Convert Images Into ASCII Format In Linux
### <a id="21"></a> Read images from standard input

To read images from standard input and prints the ASCII characters in the standard output, make use of pipe command like below.
```sh
  $ cat arch.jpg | jp2a -
```
Mind the hyphen symbol (-) at the end.

### <a id="22"></a> Write output to a file

Instead of displaying the ASCII image in the standard output, you can write it to a file as shown below.
```sh
  $ jp2a arch.jpg --output=arch_ascii
```
This command will append the ASCII output in a text file called arch_ascii. You can view the file's contents using the "cat" command:
```sh
  $ cat arch_ascii
```

### <a id="23"></a> Print images with specific height/width

You can convert the image to ASCII format and print them with a specific height or width of your choice.

To print using a specific height, for example 30 rows, simply do:
```sh
  $ jp2a --height=30 arch.jpg
```
The width will be automatically calculated from the aspect ratio of the image.

Similarly, to specify the width, run:
```sh
  $ jp2a --weight=30 arch.jpg
```
You can also combine the both options and print the image.
```sh
  $ jp2a --height=20 --width=40 arch.jpg
```

### <a id="24"></a> Print images in ASCII format in X columns and Y rows

The following command converts the given image file into ASCII and prints the output in 50 columns and 30 rows.
```sh
  $ jp2a --size=50x30 arch.jpg
```
### <a id="25"></a> Set border to ASCII characters

If you want to set border around the ASCII output, use border option like below:
```sh
  $ jp2a --border --size=50x30 arch.jpg
```
### <a id="26"></a> Print images in light/dark background

Jp2a has options to print the ASCII characters in light and dark backgrounds.
```sh
  $ jp2a --background=light arch.jpg
  $ jp2a --background=dark arch.jpg
```
### <a id="27"></a> Print images into ASCII format in dark background

Print images into ASCII format in dark background
If you view a picture with white background, but you are using a display with light characters on a dark background, you should invert the image using the invert flag.
```sh
  $ jp2a arch.jpg --invert
```
### <a id="28"></a> Print images with specific characters only
### <a id="29"></a> Download images directly from Internet
### <a id="210"></a> Convert images other than JPG/JPEG

What if you have the different image type other than the JPG/JPEG? In that case, you can use ImageMagick's Convert tool like below. ImageMagick is available in the default repositories of many Linux distributions.

On Arch Linux and its variants like Manjaro Linux:
```sh
  $ sudo pacman -S imagemagick
```
On Debian, Ubuntu, Linux Mint:
```sh
  $ sudo apt install imagemagick
```
After installing ImageMagick, run the following command to convert the given PNG format image to Jpeg/Jpg format and then convert it to ASCII format:
```sh
  $ convert arch.png jpg:- | jp2a -
```
### <a id="211"></a> Produce strict HTML output

Jp2a has an option to produce strict XHTML 1.0 output.
```sh
  $ jp2a --size=50x30 --html arch.jpg --output=arch.html
```
### <a id="212"></a> Help us to help you:

# 
