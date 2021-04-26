// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("�ݷ�", ({ "qi fang", "qi", "fang" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", 
	     "һ���ɰ���ũ����ԲԲ��������һ˫���ۺ�����ġ�\n");
        set("shen_type", 1);

        set("combat_exp", 15000);

        set("attitude", "friendly");
	set("inquiry", ([
            "���Ĳ�" : "�����԰������С�\n",
	    "�ݳ���" : "�����ҵ���\n",
		"���" : "����վ�����Ǽ�Ժ�⡣\n",
		"ʦ��" : "�����ص��������ˡ�\n",
       ]) );

	set("max_neili",500);
	set("neili",500);
	set("jiali",30);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	set_skill("force",30);
        set_skill("parry", 30);
        set_skill("sword", 30);
	set_skill("tangshi-jian",30);
	map_skill("sword","tangshi-jian");

        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/zhujian")->wield();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
   if (random(3)>1) {
	command("say ��λ"+RANK_D->query_respect(me)+"��Ϊ�������·����ǣ��ҵ�Ҫ�Ѵ�����ˡ�");
	command("cry " + me->query("id"));
	command("say ���ܰ�������취��");
   }
}

int accept_object(object me, object obj)
{
	if (obj->query("armor_type")=="cloth") {
		if (obj->query("id")=="pink cloth") {
		     command("ah");
		     command("thank "+me->query("id"));
		     command("say ��ϧ��ʦ�ֲ��ڡ�");
		     command("whisper "+me->query("id")+" ��ǰ�ҳ���ʦ���ڴ���"
			+ "�����Сɽ���档�����ǲ����Ӳ�(bocao)���ܿ���һ��ɽ����"
			+ "��������Һ���ʦ��˭Ҳ�Ҳ����ġ�");
		     me->set_temp("qi/bocao",1);
		     return 1;
                 }
		 command("thank "+me->query("id"));
                 command("say ��ϧ�ⲻ���Ұ������·���");
		 return 0;
	}
	if (obj->query("id")=="tangshi xuanji") {
                     command("ah");
                     command("cry");
		     command("say �����Һ���ʦ�ִ�ǰ��һ��ʱ�Ҽ������õ��顣");
		     remove_call_out("destbook");
		     call_out("destbook",10,obj);
		     remove_call_out("wet");
                     call_out("wet",30, me);
		     return 1;
         }
	return 0;
}

void destbook(object book){
	destruct(book);
	command("nocry");
}

void wet(object me){
	object book;
	command("cry");
	if (me->query_temp("qi/bocao") && objectp(present("qi fang", environment(me)))) {
	  	tell_object(me,"��ͻȻ�����ݷ�������ε�����ʫѡ������֮���������Գ�Щ�ּ���\n");
                tell_object(me,"����ݷ���ע���ְѡ���ʫѡ����͵�˻�����\n");
		book = new(__DIR__"obj/tangshi2");
		book->move(me);
		me->set_temp("qi/tangshi",1);
	}
} 
