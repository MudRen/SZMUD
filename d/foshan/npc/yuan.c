// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("Ԭ����", ({ "yuan ziyi", "yuan", "ziyi" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", 
	"�������ȣ�����¶��ɫ�������İ�������üͷ��һ�Ź�������˫ü�޳���Ƥ����Ȼ"
	+ "΢�ڣ�ȴ�ڲ��������������ݹ����ˡ�\n");
        set("shen_type", 1);
	set("title","�Ÿ�������������");
	set("horse_count",2);

        set("combat_exp", 500000);

        set("attitude", "peaceful");
	set("inquiry", ([
		"name" : "�ҽ�Բ���ţ�Ԭ���¡�\n",
		"Բ��" : "�㣬�㵽����˭��\n",
		"������" : "��������������Լ�ȥ��ɽ������\n",
		"�Ÿ�������" : "������Τ�����ţ����ɽ����ţ���Ҳ�ǲ�ס����\n",
		"����" : "��������ʮ�����ɵ������ˣ���Ҫ�����μӸ���˧�������˴�ᡣ\n",
		"������" : "��������ʮ�����ɵ������ˣ���Ҫ�����μӸ���˧�������˴�ᡣ\n",
		"�����˴��" : "��������Ҫȥ��\n",
		"����˧" : "һ�����޵Ĺ٣��и���������˵�ǻ��ϵ�˽���ӡ�\n",
		"������" : "һ�����޵Ĺ٣���˵�ǻ��ϵ�˽���ӡ�\n",
		"������" : "���Ǻ컨��Ĵ�Ӣ�ۣ�ǧ�������԰�ɽ��\n",
		"�԰�ɽ" : "���������塣\n",
		"�컨��" : "��ô�����ǳ�͢ӥȮ�𣿣�\n",
		"������" : "�ð������ռ�ұ��ˣ�\n",
		"���" : "������������������\n",
		"������" : "�ǿ����������ı���������ɣ�������ˮ�ء�\n",
		"������" : "���Ǻ컨��Ĵ�Ӣ�ۣ�ԧ�쵶�����\n",
		"���" : "������������\n",
		"������" : "���Ǻ컨��Ĵ�Ӣ�ۣ���������̩����\n",
		"��̩��" : "���������塣\n",
	]));

	set("max_neili",1400);
	set("neili",1400);
	set("max_qi", 900);
	set("qi", 900);
	set("jing", 900);
	set("max_jing", 900);
	set("jiali",100);
        set_skill("force", 120);
        set_skill("linji-zhuang", 120);
        set_skill("strike", 120);
        set_skill("jinding-zhang", 120);
        set_skill("finger", 120);
        set_skill("tiangang-zhi", 120);
        set_skill("whip", 120);
        set_skill("feifeng-bian", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("zhutian-bu", 120);
        map_skill("force", "linji-zhuang");
	map_skill("whip","feifeng-bian");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");

        setup();
        carry_object(__DIR__"obj/ziyi")->wear();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()
	&& environment(this_object())->query("short") == "��ͤ" ) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object me)
{
	object ring;
	object h;
    if (!me->query_temp("ziyi-zhihuan") && !ring = present("zhi huan",me)){
       command("say ��������������Ϣ�����������");
       command("kick " + me->query("id"));
       message("vision", me->name() +"��Ԭ����һ���߳����⡣\n",
                environment(me), ({me}));
       me->move("/d/foshan/road3");
       message("vision", me->name() +"���˴Ӳ�ͤ�����˳�����\n", 
                environment(me), ({me}));
	if (h = me->query("rided")) h->move("/d/foshan/road3");
	return;
    }
	else if (me->query_temp("ziyi-zhihuan")) {
	command("say ���ҵ��ǵ������𣿶��ˣ��ҵ��Ǹ������պ���");
	}
	else {
	command("say �ߣ������������˵���Ǹ�Ӣ������ô���˼ҵ�ָ����");
	message_vision("$N��$nһ�����񣬰�ָ�����˹�ȥ��\n",this_object(),me);
	command("xixi");
	destruct(ring);
	command("say �������Ͽ����˲����������������������ԭ�����İ���������㡣");
	command("say ���Ҳ���������ô�ܸɣ�����������ҵ��ҵ�һ�����ѼҴ����׵�ͷ��ҳ��");
	me->set_temp("ziyi-zhihuan",1);
	}
}

int accept_object(object me, object obj)
{
	object horse, *obs;

	if ((string)obj->query("id") != "hujia daofa") 
		return 0;

	if (!me->query_temp("ziyi-zhihuan") ){ 
	command("? " + me->query("id"));
	return 0;
	}

	obs = filter_array(children("/clone/horse/bailong.c"), (: clonep :));
        if (sizeof(obs) != 0){

//	if (query("horse_count") < 1) {
	command("thumb " + me->query("id"));
        command("say ��ϧ���˱������ҵ������ˡ�");
	return 0;
	}
	command("ah");
	command("thumb " + me->query("id"));
	command("say ��Ȼ���򵥣���������ͰѰ�������㡣");
	horse = new("/clone/horse/bailong");
	horse->move(environment(me));
	horse->set_lord(me);
	horse->set_leader(me);
	message_vision("Ԭ���½���$Nһƥ������\n", me);
	command("say ������������ı���������ɣ�����ɺ�(duhe)�ء�");
	add("horse_count", -1);
	me->delete_temp("ziyi-zhihuan");
	return 1;
}
