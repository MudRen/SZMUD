// Code of ShenZhou
// hai.c ������
// Jay 4/6/96

inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("���Ϲ�", ({"hai laogong", "hai", "laogong"}));
        set("title", "���ŷ��ܹ�");
        set("long",
                "�������ŷ�̫�ຣ�󸻣���װ�İ������ģ������Ѱ�����֡������ü�����ͷ������̫̫���ȸ���ͣ��\n"
        );

        set("gender", "����");
	set("class","eunach");
        set("attitude", "heroism");

        set("inquiry",([
                "�Թ�"  : (: ask_for_zigong :),
        ]));

        set("age", 60);
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("combat_exp", 25000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 70);
        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("damo-jian", 70);
	set_skill("shaolin-shenfa", 70);

        map_skill("dodge", "shaolin-shenfa");
        map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	map_skill("force", "hunyuan-yiqi");

        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
		"���Ϲ�������������\n",
		"���Ϲ��ӻ����ͳ�һ��Сҩƿ����С��ָ������һ���ɫ��ҩ�浽�ƴ��У��Ѿƺ�����ȥ��\n",
		"���Ϲ�˵����ҩ�ɲ��Ҷ�ԣ��Զ��˻������ġ�\n",
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/city/npc/obj/jiudai");
	carry_object("/d/xingxiu/obj/huashi");
        add_money("silver", 50);
}

void init()
{
	::init();
        add_action("do_decide", "decide");
}

string ask_for_zigong()
{
        object me;

        me = this_player();

        if( (string)me->query("gender")=="����" )
                return "����ͬ�����ˣ��αؿ�������ĵ���Ц��\n";

        if( (string)me->query("gender") == "Ů��" )
                return "�����ѷϣ���һ�����Ը������С���˴������֣�Ҫ��Ҫ���ԣ�\n";
        if ((int)me->query_str() > 28 )
                return "��λ�ú����ڴ�׳���Թ��а���հ�����ף����ס�\n";
        if ((int)me->query("age") < 16 )
                return "�ٺ١��Թ����������ջ�û�������أ�\n";

       me->set_temp("pending/zigong", 1);
        return "�Թ�����λ������ò���ã��α�... ����ϣ����������Ǹ����Թ�֮�󣬲��ɺ�ڣ����������Ѷ�(decide)�������ҡ�\n";
}

int do_decide()
{
        if( !this_player()->query_temp("pending/zigong") )
                return 0;

        message_vision(
                "$Nһҧ�����������¡���Ů��ұ��ۣ���\n\n"
                "$n��������嵽$N����֮�䣬����һ�࣬����\n\n"
                "$N��ʱ�ҽ�һ�����˹�ȥ����\n\n",
                this_player(), this_object() );
        command("chat �ˡ���");
        command("hehe");
        this_player()->delete_temp("pending/zigong");
        this_player()->set("gender","����");
//        this_player()->set("class", "eunach");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
	this_player()->set("per",(this_player()->query("per")+30)/2);
        this_player()->unconcious();
        return 1;
}

