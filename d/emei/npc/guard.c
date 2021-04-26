// Code of ShenZhou
// d/emei/npc/guard.c �ķ�
// Shan 96/07/09

inherit NPC;
string ask_me(string name);

void create()
{
	set_name("�ķ�", ({"wenfei", "wen fei", "guard"}) );
	set("rank_info/respect", "Сʦ̫");
	set("gender", "Ů��" );
	set("age", 16+random(6));
	set("long",
	  "���Ǹ����䲻��ü��Ŀ���Сʦ̫�������￴Ĺ��\n");
	set("attitude", "friendly");
        set("shen_type", 1);
        set("class", "bonze");

        set("str", 20);
        set("int", 18);
        set("con", 24);
        set("dex", 22);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);

	set("combat_exp", 2000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 3);

        create_family("������", 5, "����");

	set("book_count", random(2));
	set("jing_count", random(3)==2);
	set("xiang_count", 10);

        set("inquiry", ([
	    "here" : "������Ǳ�����ʦ����Ů����Ĺ�ˡ�\n",
	    "name" : "�����ķƣ��⼸��ʦ�����������￴�ش�ɨĹ�ء�\n",
	    "��ȥ" : "�����Ӻ����ȥ������ɽ·��һ������͵���ʮ�ŵ��գ������������ɽ��\n",
	    "�ؼ�" : "�����ʲô�飿�Ҳ�֪����������û�С�\n",
	    "ɨĹ" : "����̫���ˣ�����԰��Ұ�Ĺ�ԵĲ�����һ�¡�\n",
	    "����" : "������Ǳ�����ʦ����Ů����Ĺ�ˡ�\n",
	    "Ĺ" : "������Ǳ�����ʦ����Ů����Ĺ�ˡ�\n",
	    "������" : "��ʦ������Ҽ����¹����⼸�ղ�֪�㵽����ȥ�ˡ�\n",
	    "�����澭" : (: ask_me, "jing" :),
	    "����צ��" : (: ask_me, "book" :),
	    "����" : (: ask_me, "xiang" :),
	    "����" : (: ask_me, "xiang" :),
        ]));

	set("chat_chance", 2);
        set("chat_msg", ({
                "�ķƵ�����֪�Ӱ��ʦ��ʲôʱ�����أ�\n", 
                "�ķ��ߵ��ſڣ����˿��죬�ֻص�ʯ��ǰ���¶��顣\n", 
		"�ķƷ������е��飬�����۾������룬����������Ȼ������¡�\n", 
		"�ķƺ����飬�ߵ����ǰ������һ���飬�������Ŷ���������\n",
        }) );

        setup();
        
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

string ask_me(string name)
{
	object me = this_player();
        object book;
        object jing;
	object incense;

	if ( name == "book" ) {
        /*	if (query("book_count") < 1)
                	return "�Ǳ�������צ�����ղ����˽�ȥ���ˣ���������ɡ�";
        	add("book_count", -1);
        	book = new(__DIR__"obj/claw-book");
        	book->move(this_player());
        	return "�Ȿ������צ���������ڲ��ã��������ȥ������";
	*/
		return "����ô�������飿";
	}
	if ( name == "jing" ) {
	/*		if ((int)me->query_temp("visit_tomb") < 10) 
			return "���Ǳ��ɹ�ʦ���������ģ�����������˿���";
		if (query("jing_count") < 1)
			return "�Ҵ���ʦ�����ﳭ��һЩ�������澭���ϵĹ��򣬸ոս������ȥ���ˣ���֪ʲôʱ�򻹻�����";
		add("jing_count", -1);
        	jing = new(__DIR__"obj/jiuyin-jing1");
        	jing->move(this_player());
        	return "�ðɣ��Ҿͽ����Ȿ�������澭�������Ҵ���ʦ�����ﳭ�ġ����껹���Ҿ����ˡ�";
	*/
		return "����ô�������飿";
	}
	if ( name == "xiang" ) {
		if (query("xiang_count") < 1)
			return "������û���ˣ����´������Ҵ���ɣ���";
		add("xiang_count", -1);
        	incense = new(__DIR__"obj/incense");
        	incense->move(this_player());
        	return "������ֻ�㣬����ȥ�ɡ�";
	}
}

