//Cracked by Yujie
///d/forest/npc/cl_menwei ����
// by yujie 10 / 2001

inherit NPC;


void create()
{
	set_name("��������", 
              ({ "men wei", "menwei" }));
        set("title", "���ְ�");
	set("long", 
		"���Ƿ����������������ô��ŵ�������\n"
		"���������⣬˭�����������ý��ġ�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_neili", 100);
        set("neili", 100);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("dodge", 40);
	set_skill("cuff", 50);
	set_skill("parry", 50);

        set("inquiry", ([
                "���ְ�" : "������ǳ��ְ��ܶ����ڵء�",
                "˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
                "����" : "��λ�����������ɰ������˼�˵���㡣",
                "����ʯ" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
                "����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
        ]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object me = this_player();
	string pos;
	
           if (stringp (me->query_temp("bangs/pos"))) 
	{	call_out("bow",1,me);
		return;
	}
		
	if ( stringp ( me->query_temp("invite")) )
		call_out("agbow",1,me);
	
	return;
		
	
}

void bow(object me)
{
	if (present(me,environment(this_object())))
		message_vision("$N����$n���˸����񣬵������������˼Һã�\n",this_object(),me);
	return;
}

void agbow(object me)
{
	if (present(me,environment(this_object())))
		message_vision("$N����$n���˸����񣬵�����ӭ����������Ѿ��Ⱥ�����ʱ�ˡ�\n",this_object(),me);
	return;
}
