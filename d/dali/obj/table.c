// Code of ShenZhou
//table.c
//xQin 4/00

#include  <ansi.h>

inherit  ITEM;

void  create()
{
	set_name(WHT"石桌"NOR,  ({  "table"  }));
        set_weight(200000);
        set("long",  "这是张大理石制的桌子。\n"  );
        if(  clonep()  )
        set_default_object(__FILE__);
        else  {
        set("unit",  "张");
        set("material",  "stone");
        set("value",  2000);
        set("no_get",  1);
        set("amount",30);
                }
        setup();
}
