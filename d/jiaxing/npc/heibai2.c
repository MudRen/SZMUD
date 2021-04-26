// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("�ڰ���",({ "heibai zi","zi","heibai" }) );
        set("gender", "����");
        set("age", 55);
	set("long",
		"��üĿ���㣬ͷ�����ڶ�Ƥ�����ף�"
		"�ƺ�һ�߽�ʬģ����\n");
       // set("nickname","");
        set("title","÷ׯ��ׯ��");
        set("combat_exp", 47000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 85);
	set_skill("force",85);
        set_skill("parry", 85);
        set_skill("dodge", 85);
	set_skill("hammer",85);

	set("max_neili",450);
	set("neili",450);
	set("jiali",45);

        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/qiping")->wield();
	carry_object("/d/taishan/obj/mianzhao");
}

void init()
{
        object ob;

        ::init();
	add_action("do_suck","suck");
        if (interactive(ob = this_player())) {
                remove_call_out("check_sangong");
                call_out("check_sangong",1,ob);
	}
}

void check_sangong(object me)
{

	if (environment(me)->query("short")!="����")
	return;
	if (me->query("max_neili")>0 || !me->query("mz_neili")) {
		command("look "+me->query("id"));
		command("say ��ô�ĵ��ӣ�����ð�������У�");
		tell_object(me,"�ڰ����ֳ��������������������������ᣡ\n\n");
		me->set("startroom","/d/city/kedian");
		me->set_temp("tieslept",0);
		me->move("/d/jiaxing/mzgate1");
		message_vision("�ڰ��Ӱ�"+me->name()+"���˳�ȥ��\n",
			this_object());
		destruct(this_object());
		return;
	}
	command("say �����������������ؾ���");
	command("bow "+me->query("id"));
	tell_object(me,"��һ���ڰ��ӽ����ݣ�ͻȻ���һ���������������(suck heibai zi)"
			"��������\n\n");

	me->set_temp("suck/can",1);
	return;
}

int do_suck(string arg)
{
	object me=this_player();
	if (!me->query_temp("suck/can") || 
             !(arg=="heibai zi" || arg=="zi" || arg=="heibai")) 
	return 0;

	if (present("liaokao",me)) {
		write("�������취ȥ������\n");
		return 1;
	}

	message("vision",me->name()+"ͻȻ����ץס�˺ڰ��ӵ�����\n",
		environment(me),({me}));
	write("��ͻȻ����ץס�˺ڰ��ӵ�����\n");
	command("fear");

	me->set("max_neili",me->query("mz_neili"));
	write("��о������Ӻڰ��ӵ������ڹء�����ء�����Ѩ��ԴԴ���룬"
		"��������ָֻ��ˣ�\n");
	this_object()->unconcious();
	return 1;
}





