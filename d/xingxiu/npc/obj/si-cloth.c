// Code of ShenZhou
// si-cloth.c ˿��
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("˿��", ({ "si juan","si" }) );
        set_weight(2000);
	
        if( clonep() )
                set_default_object(__FILE__);
        else {
	        set("unit", "��");
		set("long", "һ���׵�˿�����������(bao)������\n");
                set("material", "cloth");
                set("value", 500);
                set("armor_prop/armor", 5);
        }
        setup();
}

void init()
{
	add_action("do_bao","bao");
}


int is_special() {return 1;}

int do_bao(string arg)
{	string what;
	object ob,temp,obj=this_object();

        if(!arg || sscanf(arg,"%s",what)!=1)
                return notify_fail("��Ҫ��ʲô�����ϰ�˿�\n");

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("������û��" + what + "��\n");

        if (! ob->query("armor_prop/armor"))
                return notify_fail("��ô���������˿��ɲ���Ϲ����\n");

	if (ob->query("id")=="si juan")
		return notify_fail("���Ѿ�����˿���ˣ�\n");

	if ( ob->is_unique() ) // added by sdong so that unique stuff cannot be duplicated
		return notify_fail("��̫���ˣ�����ס��\n");


        message_vision(GRN"$NС������ذ�˿�����" +ob->query("name")+"�ϡ�\n"NOR, this_player());
	obj->weight(ob->weight());
	obj->set("name","˿�������"+ob->query("name"));
	obj->set("long",ob->query("long")+"�������������һ��˿�\n");
	obj->set("armor_prop/armor",ob->query("armor_prop/armor"));
//	obj->set("no_sell");
	obj->set("value",0);
	
	if (temp=this_player()->query_temp("armor/cloth") && temp==ob)
		{destruct(ob);
		 obj->wear();
		}		
	destruct(ob);
	return 1;
}
