// Code of ShenZhou
#include  <ansi.h>

inherit  ITEM;

void  create()
{
	set_name(YEL"�齫��"NOR,  ({  "table"  }));
        set_weight(200000);
        set("long",  "�������Ե���ɫ�Ĵ����Ƴɵ��齫����\n"  );
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
