// Code of ShenZhou
// Summer 9/26/1996.
// Update Lara 01/10/26
inherit NPC;
string ask_me();

void create()
{
	set_name("��ľ���", ({ "jiamu huofo", "jiamu", "huofo" }));
	set("long", 
"���Ǳ��µ�������Ļ���뷢�԰ס�����С�������г���һֱǱ�ķ𷨣���δ̤\n"
"ɽ��һ����\n");
//	set("title","����������");
	set("gender", "����");
	set("age", 80);
	set("attitude", "friendly");
	set("class","bonze");
	set("shen_type", 1);
	set("str", 33);
	set("int", 35);
	set("con", 29);
	set("dex", 29);
	
	set("max_qi", 1000);
	set("max_jing", 850);
	set("jiali", 40);
	set("combat_exp", 80000);
	set("score", 5000);

	set("inquiry", ([
                "����" : (: ask_me :),
		"�ؾ�" : "�����»��Ҫȥ��",
        ]));

        set("book_count", 1);
        setup();
        carry_object(__DIR__"obj/lamajiasha")->wear();
}
string ask_me()
{
        mapping fam;
	object wage;
        object me = this_player();

        if (!(fam = me->query("family")) || fam["family_name"] !="ѩɽ��"
	&& fam["family_name"] !="Ѫ����" && me->query("class") !="lama")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query_skill("lamaism", 1) < 60)
		return "�㲻��Ҫ���";
	if (me->query("age") < 25 && me->query("lama_wage") > me->query("mud_age") - 86400)
		return RANK_D->query_respect(this_player()) +
                "�����û������������Ҫ���";
	if (me->query("age") > 24 && me->query("lama_wage") > me->query("mud_age") - 259200)
		return RANK_D->query_respect(this_player()) +
                "�����û������������Ҫ���";
	if (me->query_skill("lamaism", 1) >= 60
	&& me->query_skill("lamaism", 1) < 90){
	wage = new("/clone/money/gold"); 	
	wage->set_amount(2);
	wage->move(me);        
	me->set("lama_wage",me->query("mud_age"));
	message_vision("��ľ���ת���ó�һ������ݸ�$N��\n", me);
                return "�������˽���Ĺ�����պá�";
	}
	if (me->query_skill("lamaism", 1) >= 90
        && me->query_skill("lamaism", 1) < 120){
	wage = new("/clone/money/gold");
        wage->set_amount(8);
	wage->move(me);        
        me->set("lama_wage",me->query("mud_age"));
	message_vision("��ľ���ת���ó�һ������ݸ�$N��\n", me);
                return "�������˽���Ĺ�����պá�";
        }
	if (me->query_skill("lamaism", 1) >= 120
        && me->query_skill("lamaism", 1) < 150){
        wage = new("/clone/money/gold");
        wage->set_amount(15);
	wage->move(me);        
        me->set("lama_wage",me->query("mud_age"));
        message_vision("��ľ���ת���ó�һ������ݸ�$N��\n", me);
                return "���Ƿ�ү����Ĺ�����պá�";
        }
	if (me->query_skill("lamaism", 1) >= 150){ 
        wage = new("/clone/money/gold");
        wage->set_amount(20);
	wage->move(me);        
        me->set("lama_wage",me->query("mud_age"));
	message_vision("��ľ���ת���ó�һ������ݸ�$N��\n", me);
                return "���Ƿ�������Ĺ�����պá�";
        }	
}
