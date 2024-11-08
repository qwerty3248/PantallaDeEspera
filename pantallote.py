import tkinter as tk
import random
from PIL import Image, ImageTk
import time

# Crear la ventana principal
root = tk.Tk()
root.title("Pantalla de Espera")
root.geometry("900x900")  

# Fondo verde
root.configure(bg="green")

# Cargar las imágenes
image1 = Image.open("knekro1.png")  
image2 = Image.open("knekro2.png")  

# Convertir las imágenes a formato adecuado para Tkinter
image1_tk = ImageTk.PhotoImage(image1)
image2_tk = ImageTk.PhotoImage(image2)

# Crear un lienzo para dibujar las imágenes
canvas = tk.Canvas(root, width=900, height=900, bg="green", bd=0, highlightthickness=0)
canvas.pack()

# Función para actualizar la posición de las imágenes
 
X = True
def update_position():
    # Borrar las imágenes anteriores
    canvas.delete("all")
    global X
    # Elegir aleatoriamente una imagen y una posición
    #selected_image = image1_tk if random.choice([True, False]) else image2_tk
    if X:
    	selected_image = image1_tk
    	X = False
    else:
    	selected_image = image2_tk
    	X = True	
    x_pos = random.randint(0, 550)  # Coordenada X aleatoria
    y_pos = random.randint(0, 700)  # Coordenada Y aleatoria
    
    # Dibujar la imagen en la nueva posición
    canvas.create_image(x_pos, y_pos, image=selected_image)
    
    # Llamar nuevamente a esta función después de un pequeño retraso
    root.after(200, update_position)  # 200 ms de retraso para crear la animación

# Iniciar la animación
update_position()

# Ejecutar la ventana
root.mainloop()

