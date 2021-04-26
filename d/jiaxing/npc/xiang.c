// Code of ShenZhou
// xiang.c  <-- ������, not  ����ү.
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("������",({ "xiang wentian","xiang" }) );
        set("gender", "����");
        set("age", 45);
	set("long",
		"����ò���ǣ�һ���������ʵĻ��׳��봹����ǰ������Զ��"
		"������غ��������֮����\n");
        set("nickname","��������");
        set("title","���������ʹ");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");
        set_skill("unarmed", 90);

	set_skill("force",90);
        set_skill("parry", 90);
        set_skill("dodge", 90);

	set("jing",35);
	set("max_jing",215);
	set("eff_jing",35);
	set("qi",100);
	set("eff_qi",100);
	set("con",-9);
//	set("max_neili",500);
//	set("neili",500);
	set("jiali",45);
       setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_yishang","yishang");
}

int accept_object(object me, object obj)
{
        switch ((string)obj->query("name")) {
	case "��ҩ":
       	message("vision",me->name()+"��������һ����ҩ��\n",environment(me),
	    ({me}));
	command("thank "+me->query("id"));
	if (!query("giveyao")) {
	  set("giveyao",1);
	  call_out("eatyao",1);
	  call_out("create_shashou",10);
	}
	return 1;
	case "����":
        message("vision",me->name()+"��������һֻ����\n",environment(me),
            ({me}));
        command("say ��λ"+RANK_D->query_respect(me)+"�ľ���֮����ĳû�ݲ�����");
	command("bow "+me->query("id"));
	command("look "+me->query("id"));
	command("ah");
          command("say �����������������ˡ����м����������������������ҽ����"
		"�������ˣ���֪����Ըȥҽ��(yishang)��");
	me->set_temp("yishang",1);
	return 1;
	}
}

void eatyao()
{
	command("fu jin");
	return;
}

void create_shashou()
{
  object s1,s2,s3;
	say("ͻȻ����������������ݺݵľ�װ���ӡ�\n\n");

	s1 = new(__DIR__"shashou");
	s2 = new(__DIR__"shashou");
	s3 = new(__DIR__"shashou1");
	s1->move(environment(this_object()));
        s2->move(environment(this_object()));
        s3->move(environment(this_object()));

	return;
}
	
int do_yishang()
{
	object me=this_player();
	object o1,o2,o3,o4;

	if (!me->query_temp("yishang"))
		return 0;

	message("vision",me->name()+"���������������С�\n", environment(me),({me}));
	me->move("/d/jiaxing/mzgate");
	this_object()->move("/d/jiaxing/mzgate");

	write("����������������һ��ׯԺǰ��\n");
          command("say ÷ׯ��λׯ�������������������������ǣ����ǻ�����ҽ�ˡ�");
	command("say ���������ײ����֡�");
	o1 = new(__DIR__"obj/qipu");
	o2 = new(__DIR__"obj/xinglutu");
	o3 = new(__DIR__"obj/shuaiyitie");
	o4 = new(__DIR__"obj/guanglingsan");
	o1->move(me);
	o2->move(me);
	o3->move(me);
	o4->move(me);
        message_vision("$n�ݸ���$N�������\n", me, this_object() );
        command("say �㵽ʱ���⼸������ֱ������ׯ����");
	command("give qiu to "+me->query("id"));
	command("say ����͵��������ͷ�Ƚ�ǰ��������򽻸�����");
	command("bow "+me->query("id"));
	command("bye");
	destruct(this_object());
	return 1;
}
