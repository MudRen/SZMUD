// Code of ShenZhou
// Summer, 10/16/96. 

inherit NPC;

string ask_me_1();
string ask_me_2();

void create()
{
	set_name("��ǧ��", ({"zu qianqiu", "zu"}));
	set("long",
		"һ���������͵�����������������Ƥ��һ������ǣ���������ļ������ӣ�\n"
		"��������������һƬ�͹⣬��������һ�������ȡ�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");

	set("age", 50);
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("jiali", 40);
	set("combat_exp", 500000);
	set("apply/attack", 50);
	set("apply/defense", 50);
	set("score", 100);
	set("chat_chance", 20);
        set("chat_msg", ({
                "��ǧ�������������ͷ������Ƶ�Ǯ��û�С����ϸ���������һ���Ҳ���Ӽ��ҡ�\n",	
		"��ǧ�����˵�������ϸ���̯�ϸ�Ů�����Ŀ첻���ˣ����쾡ι��Щ��Ԫ����������ʲ��ģ���һ�����Ҳû�С�\n",
	}) );
	set("inquiry", ([
		"������" :    (: ask_me_1 :),
		"��Ԫ��" :    (: ask_me_2 :),
		"��ҩ" : "�š�������ͷ�ӵĲ�ҩ�صý���û�������֡�\n",
		"ҩ��" : "�͹�Ҫ�ܳ��ü�Ǯ���ҵ��ǿ��Ե����ϸ����Ƕ���һ�ʡ�\n",
	]));

	set("wan_count", 5);
	set("dan_count",  5);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me_1()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return "��ͷ�ӿ��ý������Լ���Ҫ��Ū������";

	if (  present("yangxin wan", this_player()) )
		return "�Ҳ��Ǹ�����������";

	if (query("wan_count") < 1) return "��ͷ�ӿ��ý������Լ���Ҫ��Ū������";

	say("��ǧ��̾�˿�������������ҳ���̫�ࡣ�����ȣ�û�뵽������\n");
	this_player()->set_temp("marks/��", 1);
	return "����Ҫ�ͱ���������ɡ�ֻҪһ���ƽ�\n";
}
string ask_me_2()
{
        object ob;

        if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return "��ͷ�ӿ��ý������Լ���Ҫ��Ū������";

        if (  present("guiyuan dan", this_player()) )
                return "�Ҳ��Ǹ�����������";

        if (query("dan_count") < 1) return "��ͷ�ӿ��ý������Լ���Ҫ��Ū������";

        say("��ǧ��̾�˿�������������ҳ���̫�ࡣ�����ȣ�û�뵽������\n");
        this_player()->set_temp("marks/��", 1);
        return "����Ҫ�ͱ���������ɡ�ֻҪһ���ƽ�\n";
}
int accept_object(object me, object ob)
{
	object yang, gui;

	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/��") ) {
        yang = new(DRUG_D("yangxin"));
        yang->move(me);
	add("wan_count", -1);
        me->delete_temp("marks/��");
        message_vision("��ǧ��ӻ����ͳ�һ��������ݸ�$N��\n",me);
        return 1;
        }

	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/��") ) {
        gui = new(DRUG_D("guiyuan"));
        gui->move(me);
        add("dan_count", -1);
	me->delete_temp("marks/��");
	message_vision("��ǧ��ӻ����ͳ�һ����Ԫ���ݸ�$N��\n",me);
	return 1;
	}
	
	say(
	"��ǧ��һ�漱æ��Ǯ��������һ��Ц����˵����" + RANK_D->query_respect(ob) + "��������ҩ������˵��С��û��Ū�����ġ�\n");
	return 1;
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
