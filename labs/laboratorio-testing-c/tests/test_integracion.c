#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

void test_compra_con_descuento(void){
    Carrito c;
    carrito_init(&c);

    Producto pan= {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);

    ASSERT_IGUAL(1300,carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(1300,10));
}

void test_agregar_hasta_llenar(void){
    printf("\n[agregar hasta llenar]\n");

    Carrito c;
    carrito_init(&c);

    Producto leche = {"Leche",350,1};

    carrito_agregar(&c, leche);
    carrito_agregar(&c, leche);
    carrito_agregar(&c, leche);
    carrito_agregar(&c, leche);

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0,carrito_agregar(&c, leche));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
     test_compra_con_descuento();  
     test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
