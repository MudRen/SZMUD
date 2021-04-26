// Code of ShenZhou 
// /kunlun/shufang2.c
// by keny

#include <ansi.h>
inherit ROOM; 

string* books = ({
"laozi1",
"daodejing-i",
"laozi2",
"daodejing-ii",
"laozi8",
"daodejing-i",
"laozi13",
"daodejing-ii",
"laozi18",
"daodejing-i",
"daodejing-ii",
"laozi16",
});

void create() 
{
set("short", WHT"书房西"NOR);
set("long",@LONG 
这里是书房西，靠墙一排大书架，摆放着很多的书籍，昆仑三圣何足道以
道学为修，故昆仑派一直引以道学心法来作心法，一眼望过去，似乎有关于 
道学方面的书，放在书架上。
LONG
);

set("exits", ([ 
"west"  : __DIR__"shufang",
]));
set("cost",1); 
set("objects", ([ 
"/d/zhongnan/obj/"+books[random(sizeof(books))] : 1,
"/d/zhongnan/obj/"+books[random(sizeof(books))] : 1,
"/d/kunlun/obj/taoism.c" : 1
]));
setup();
replace_program(ROOM); 
}

