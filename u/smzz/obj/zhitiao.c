//by smzz 02.6.8
#include <ansi.h> 
inherit ITEM; 
void create() 
{
     set_name(HIG"纸条"NOR, ({"zhitiao"})); 
set("long", HIC"一张宣纸上面写着：\n"NOR
""HIG"                此山是我占，此房是我造\n"
"                要想出此处，除非巫师来\n"
"要是没有巫师的话，~~~~~嘿嘿~~~~~就好好的在这里看看什么东西吧，没准能 \n" 
"够找到出口。这里有电脑(diannao)、对联(duilian)、匾(bian)\n"NOR);
     set("unit", "张"); 
setup(); 
}
