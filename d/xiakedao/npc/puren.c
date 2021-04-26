//Cracked by Roath
// puren.c ���͵�����
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_weapon();
int ask_armor();
void greeting(object);

string* armors = ({
	"/clone/armor/beixin",
	"/clone/armor/goupi",
	"/clone/armor/tie-beixin",
	"/clone/armor/tiejia",
});

string* weapons = ({
	"/clone/weapon/caidao",
	"/clone/weapon/branch1",
	"/clone/weapon/branch2",
	"/clone/weapon/branch3",
	"/clone/weapon/branch4",
	"/clone/weapon/changjian",
	"/clone/weapon/duanjian",
	"/clone/weapon/stick",
	"/clone/weapon/stone",
});

void create()
{
	set_name("����", ({ "pu ren", "pu"}));
	set("long", "��\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "����");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 50000);
	set("score", 1000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("cuff", 70);
	set_skill("sword", 70);
	
	set("inquiry", ([
			"����"   :  (: ask_weapon :),
			"����"   :  (: ask_armor :),
			"��ԭ"   : 	(: ask_leave :),
			"����"   : 	"������������ɽ\n",
			
		]));
	set("armor_count", 10);
	set("weapon_count", 10);
	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
	say("����΢΢һЦ˵������λ" + 
			RANK_D->query_respect(me) + "��ɽ·��Ұ·ʱҪС��Ұ�ޣ��ϻ��Ͷ��߼��˾�ҧ�ġ�\n");
	say("����˵���������Ͽ��е������Ķ���? ��������ʯ�����֦������������ǿ��Ĺ�������\n");
	say("����˵������������������װ���Լ�(wield item)�����û�������ȥ��(buy item)��\n");
	say("����˵���������������м�������Ҫ�Ļ��͸�����(ask pu about ����)��\n");
	say("����˵���������������Щ������������Ƥ��ţƤ��Ƥ���ģ������׵ȵȡ�\n");
	say("����˵������Щ������������ķ����������оͿ촩�ϰ�(wear item)��\n");
	say("����˵�����������Ҳ����һ������Ҫ������Ҫ��(ask pu about ����)��\n");

}
int ask_leave()
{	
	say("����ҡ��ҡͷ˵����û�е���ͬ�⣬��ɲ���˽���뵺��\n");
	return 1;
}
int ask_weapon()
{	int i;
	object you = this_player();
	object weapon;
	if (query("weapon_count") < 1)
	{	say("���˵�ͷ�����Ϸ��˰��죬��Ǹ��Ц��Ц˵�����Բ���û�ˡ�\n");
		return 1;
	}
	
	for( i = 1; i < sizeof(weapons); i++ )
   	{	if (  present(weapons[i]->query("id"), you) )
		{	say("����������üͷ˵�������˻�Ҫ����̫̰���˰ɡ�\n");
			return 1;
		}
		else if (present(weapons[i]->query("id"), environment(you)))
		{	say("����������һָ�����ϲ���������Ҫ�Ļ��ͼ��߰ɡ�\n");
			return 1;
		}
	}
	weapon = new(weapons[random(sizeof(weapons))] );
	say("���˴������ҳ�һ" + weapon->query("unit") + weapon->query("name") + "�����˸��㡣\n");
	weapon->move(you);
	add("weapon_count", -1);
	return 1;
}
int ask_armor()
{	int i;
	object you = this_player();
	object armor;
	if (query("armor_count") < 1)
	{	say("���˵�ͷ�����Ϸ��˰��죬��Ǹ��Ц��Ц˵�����Բ���û�ˡ�\n");
		return 1;
	}
	for( i = 1; i < sizeof(armors); i++ )
   	{	if (  present(armors[i]->query("id"), you) )
		{	say("����������üͷ˵�������˻�Ҫ����̫̰���˰ɡ�\n");
			return 1;
		}
		else if (present(armors[i]->query("id"), environment(you)))
		{	say("����������һָ�����ϲ���������Ҫ�Ļ��ͼ��߰ɡ�\n");
			return 1;
		}
	}
	armor = new( armors[random(sizeof(armors))] );
	say("���˴������ҳ�һ" + armor->query("unit") + armor->query("name") + "�����˸��㡣\n");
	armor->move(you);
	add("armor_count", -1);
	return 1;
}