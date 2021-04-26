// Code of ShenZhou
inherit NPC;
inherit F_DEALER;
string ask_me(object who);

void create()
{
	set_name("���Ϻ�", ({ "wang laohan", "wang", "laohan" }));
	set("shen_type", 0);

	set("str", 30);
	set("con", 30);
	set("dex", 18);
	set("gender", "����");
	set("age", 55);
	set("long",
		"����һ��ͷ�����׵���ͷ��æ�ſ��ձ���ͷҲ��̧��\n");
	set("combat_exp", 400000);
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set_skill("force", 110);
	set_skill("huntian-qigong", 100);
	set_skill("xiaoyaoyou", 100);
	set_skill("club", 100);
	set_skill("shexing-diaoshou", 100);
	set_skill("hand",100);
        set_skill("dodge", 100);
        set_skill("parry", 100);

	map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "shexing-diaoshou");

        prepare_skill("hand", "shexing-diaoshou");

	set("attitude", "friendly");
	set("inquiry", ([
		"������" : "������û��˵����\n",
		"л�̿�" : "��˵�Ǹ�������ߵĹ��ˡ�\n",
		"�ձ�" : "�ҵ��ձ��ֺó��ֱ��˵ġ�\n",
		"����" : "�ҵ������ֺó��ֱ��˵ġ�\n",
		"���ͨ" : (: ask_me :),
	]));
	
	set("vendor_goods", ({
		__DIR__"obj/shaobing",
		__DIR__"obj/youtiao",
	}));

	setup();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string ask_me(object who)
{
        int i;
	object cake;
        if( (random(10) < 5) || is_fighting() )
                return "�ҡ���֪����\n";

        message("vision",
		"���Ϻ��������Ȼ֪�����ӵ����֣��͸ö�������Щ���������ɣ�\n"
                "���ͨ���һ�����е�������Ȼ��ˣ����ӽ��췴�����ȥ������ƴ�ˡ���\n" 
                "���ͨȡ��һ���йٱ��������С�\n" ,
                environment(), this_object() );

        set("attitude", "aggressive");
        set_name("���ͨ", ({ "wu daotong", "wu", "daotong" }));
	kill_ob(this_player());
        carry_object("/clone/weapon/panguanbi")->wield();
	cake = new(__DIR__"obj/shaobing2");
	cake->move(this_object());
        return "���Ȼ֪�����ӵ����֣��͸ö�������Щ���������ɣ�\n";
}

void unconcious()
{
	object ob = this_object();
	object cake;

        message_vision("\nͻȻ��ֻ��$N�ͳ�һ���ձ��̽�����漴��ص����ˣ�\n",
                ob);
	if (cake = present("shaobing",ob)) destruct(cake);
	ob->unconcious();
}

void die()
{
        object ob = this_object();
        object cake;

        message_vision("\nͻȻ��ֻ��$N�ͳ�һ���ձ��̽�����漴��ص����ˣ�\n",
                ob);
        if (cake = present("shaobing",ob)) destruct(cake);
        destruct(ob);
}

	

