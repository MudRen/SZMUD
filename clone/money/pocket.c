// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"���"NOR, ({ "red pocket", "hong bao", "bao", "li shi"}) );
	set_weight(30);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
                set("long", "����һֻ��ɫ�����Ƿ⣬����ϲ�������д�š���ϲ���ơ��������֡�\n");
		set("value", 88);
		set("material", "paper");
	}
	setup();
}

int is_container() { return 1; }

int reject(object ob) 
{ 
        if (ob && (ob->query("money_id")=="ten-cash" ||
		ob->query("money_id")=="hundred-cash" )) return 0;

        notify_fail("���Ƿ���ֻ��װ��Ʊ��\n");
        return 1;
}

