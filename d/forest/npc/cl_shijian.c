// Code of ShenZhou
// /d/huanghe/changle/npc/shijian.c �̽�
// by aln 2 / 98

#include <ansi.h>
inherit NPC;

string ask_shi();
string ask_niren();

void create()
{
	set_name("�̽�", ({ "shijian" }));
	set("long", 
"���ǳ��ְ�����СѾ�ߣ���������Բ�Σ���Ҳ���Ŀ�ϲ��\n"
"��ͷ���Լ����ɣ�ѩ�׵ĳ���̤��һ˫�廨��Ь�С�\n");
	set("gender", "Ů��");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 20);
   
	set("max_qi", 500);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 20);

        set("inquiry", ([
                "ʯ����" : (: ask_shi :),
                "��ү" : (: ask_shi :),
                "���˶�" : (: ask_niren :),
        ]));
	setup();
	carry_object("/d/city/obj/pink_cloth")->wear();
}
string ask_shi()
{
	this_player()->set_temp("ask_shi",1);
	
        return "����ǰ�ź��ʯ������ү������һ�����ˡ�������һ�����˶����������أ�����Щû���·�����ż��\n";
}

string ask_niren()
{	object me=this_player();
	object *obs , ob;
	
	if (me->query_temp("ask_shi") != 1)
		return "���Ȼ�����������ѽ��\n";
		
	if (!stringp (this_player()->query_temp("bangs/pos")))  
		return "�Ҳ��ܸ����㣬�����ǰ��������������ʲ���˵�ġ�\n";
		
	obs = filter_array(children("/d/huanghe/obj/niren.c"), (: clonep :)); 
	
	if (sizeof(obs) > 0) 
                return "�������˶����Ѿ�������������ˡ�\n";
		
	ob = new("/d/huanghe/obj/niren");
	ob->move(me);
        message_vision(CYN"$N˵�������ǲ���Ҫ��������ѽ�������ϸ���ȥ�á�\n"NOR,this_object());
        message_vision("$N�ڹ�����������һ���ó���һ������ӣ�����װ��һ��������ż��\n",this_object());
        message_vision("$N�ݸ���һ��������ż��\n",this_object());
                 CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ��һ��������ż��", me->query("name")));

	return "�����ʯ��ү�����˶������պ��ˡ�\n";
}

	


		
	



