// Code of ShenZhou
//table.c
//xQin 4/00

#include  <ansi.h>

inherit  ITEM;

void  create()
{
	set_name(WHT"ʯ��"NOR,  ({  "table"  }));
        set_weight(200000);
        set("long",  "�����Ŵ���ʯ�Ƶ����ӡ�\n"  );
        if(  clonep()  )
        set_default_object(__FILE__);
        else  {
        set("unit",  "��");
        set("material",  "stone");
        set("value",  2000);
        set("no_get",  1);
        set("amount",30);
                }
        setup();
}