// Code of ShenZhou
// /kungfu/class/murong/baichuan.c
// Sure  5.13.2001

#include <ansi.h>
inherit NPC;
//inherit F_SSERVER;
inherit F_MASTER;

int auto_perform();
string ask_me();
void create()
{
	set_name("�˰ٴ�",({"deng baichuan","deng","baichuan"}) );
	set("gender","����");
	set("long","������������������ƣ��ƺ������˲��ٵķ��ꡣ\n");
	set("title","�ٻ�������");
	set("age",53);

	set("con",23);
	set("dex",20);
	set("int",21);
	set("str",22);
	set("jing",3000);
	set("max_jing",3000);
	set("qi",3000);
	set("max_qi",3000);
	set("jingli",4000);
	set("max_jingli",4000);
	set("neili",4000);
	set("max_neili",4000);
	set("combat_exp",3000000);

	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("finger",300);
	set_skill("literate",300);
	set_skill("canhe-zhi",300);
	set_skill("douzhuan-xingyi",300);
	set_skill("murong-shenfa",300);

	map_skill("finger","canhe-zhi");
	map_skill("force","douzhuan-xingyi");
	map_skill("parry","canhe-zhi");
	map_skill("dodge","murong-shenfa");

	prepare_skill("finger","canhe-zhi");

	create_family("����Ľ��", 19, "����");

	set("inquiry", ([
		"����ͬ": "�����ҵ��ֵܡ�",
		"Ľ�ݸ�" : "���Ǽҹ���æ�ڴ��£�ûʱ��Ӵ��㣬�㻹����ذɣ�",
		"����Ľ��" : "�ٺ٣����ǲ��������Ҽҹ��ӵġ��Ա�֮������ʩ������ \n"
					"�����ˣ� \n",
		"Ľ�ݲ�" : "��ү��ͻȻ������徣�����Ӣ������ѽ��������",
					]) );
	
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
			
		setup();

	carry_object("/d/murong/obj/qingyi")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

#include "/kungfu/class/murong/master.h"
}