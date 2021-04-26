
// Code of ShenZhou
// /d/changbai/npc/tian.c

inherit NPC;

void create()
{
        set_name("���ũ", ({ "tian guinong", "tian" }));
        set("nickname", "�����ű���������");
        set("long",
"�����������ű������������ũ��\n"
"�������������������������ϸ���һ��������\n");
        set("gender", "����");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1200);

        set("jiali", 40);

        set("combat_exp", 700000);

        set_temp("apply/armor", 30);

        set_skill("force", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("wuxingbu", 160);
        set_skill("ding-force", 160);
        set_skill("wuxing-quan", 140);
        set_skill("sword", 160);
        set_skill("wugou-jianfa", 160);

        map_skill("dodge", "wuxingbu");
        map_skill("force", "ding-force");
        map_skill("sword", "wugou-jianfa");
        map_skill("parry", "wugou-jianfa");
        map_skill("unarmed", "wuxing-quan");

        prepare_skill("unarmed", "wuxing-quan");
	set("inquiry", ([

		"��һ��" : 
		"���ĺ��ҵ����ǳ�����������˵������һ�ѱ�����",
		"�������" : "���ĺ��ҵ����ǳ�����������˵������һ�ѱ�����",
        ]) );

        setup();

        carry_object("/d/changbai/obj/qinggang-jian")->wield();
        carry_object("/d/dali/obj/zipao")->wear();
}

int accept_object(object me, object obj)
{
        object where = environment(this_object());object ob = this_player();

        if ( obj->name() == "���ҵ�����ƪ" && obj->query("id") == "hujia daofa" ) {call_out("create_exit", 1, where);
        command( "oh" );
	command("say ���Ȼ�ҵ��˺��ҵ�������ȥ��һ�º������ķ�Ĺ�ɡ�\n");
           return 1;
        
};      command( "hmm" );
        command( "say ������ⶫ����ʲ�᣿" );
           
        return 0;
}

void create_exit(object where)
{
        where->set("exits/southdown","/d/changbai/fen");
}