def hex_to_rgb(hex):
    return str(tuple((int(hex[i:i+2], 16) for i in (0, 2, 4))))

file1 = open('pixelColorList(Red).txt', 'r')
file = open('pixelColorList(Red).txt', 'a')

lines = file1.readlines()
file.write("-"*10+"color RGB code(Red)"+"-"*10+"\n")

for line in lines:
    file.write(hex_to_rgb(line))
    file.write("\n")

file.close()
file1.close()
