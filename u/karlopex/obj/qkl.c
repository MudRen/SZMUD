/*-------------------------------------------------------------
** �ļ���: qianceng-xue.c
** Copyright (c) 2000-2001
** ������: Ҷ��
** ��  ��: 2001/08/13
** ��  ��: �ɿ���
**-----------------------------------------------------------*/
#include <ansi.h>
inherit ITEM;

string *paizi = ({HIW"������"NOR,HIY+"��ܽ"+NOR,HIY+"���"+NOR,HIC+"Kisses"+NOR,HIC+"M&M"+NOR});
void create()
{
	string pz = paizi[random(sizeof(paizi))];
        set_name(pz+YEL"�ɿ���"NOR, ({"qiaoke li"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("s_name","�ɿ���");
                set("long", "����һ��"+pz+"��Ʒ�Ĵ��ɿ�����\n");
		set("unit", "��");
                set("value", 100);
                set("remaining", 16);
        }

        setup();
}

void init()
{
        add_action("do_drink", "eat");
}

int do_drink(string arg)
{
	int mjl = 5 + random(10);
	
        if (arg!="qiaoke li") return 0;
        if (this_player()->is_busy())
                return notify_fail("����һ��������û����ɡ�\n");

        set("value", 0);
	if ((int)this_player()->query("food") 
                >= (int)this_player()->max_food_capacity() ) 
		return notify_fail("���Ѿ��Ե�̫���ˣ���Ҳ�Ų����κζ����ˡ�\n"); 

        this_player()->add("food", random(2));

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        add("remaining", -4);
        if (query("remaining")) {
		message_vision("$N����һ��"+this_object()->name()+"���������ֻ����˿һ��Ļ�˳��\n",this_player());
        } else {
		message_vision("$N�����һ��"+this_object()->name()+"Ҳ�������ֻ����˿һ��Ļ�˳��\n",this_player());
			if (this_player()->query("add_jingli") != "Added"){
	                this_player()->add("max_jingli",mjl);
	                this_player()->add("eff_jingli",mjl);
	                this_player()->set("add_jingli","Added");
                }
                destruct(this_object());
        }
        return 1;
}

