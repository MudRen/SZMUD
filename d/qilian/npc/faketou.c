// Code of ShenZhou
// Summer, 10/16/96. 

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();

void create()
{
	set_name("��ͷ��", ({"laotou zi", "laotou"}));
	set("long",
		"���˼������֣�ͷ���Ǿ���û�еģ�һ���ȱ��ҷʵ��Դ��ᰲ��˫��֮�ϣ�\n"
		"���Ƴ����µ�֮ʱ���������ص�ͷһ颣�������Դ����£���ձǿ�ȫ����\n"
		"�ᳶ�˿�ȥһ�㡣\n"
	);


	set("gender", "����");
	set("attitude", "friendly");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 40);
	set("combat_exp", 500000);
	set("score", 100);
	set("chat_chance", 8);
        set("chat_msg", ({
                "��ͷ�����������������Ƶꣿһ���������ҩҲû�С������ϰ�Ҳ��֪�㵽����ȥ�ˡ�\n",	
		"��ͷ�Ӷ���˵������λ�͹ٿ��м�������ĵ��ϰ壿�����ȣ���Ů�����Ŀ첻���ˣ����뵽������ҵ��ҩ��\n",
		"��ͷ��ͻȻ�ŵ���������������һ�ԣ��͹���������ҩ���������Ұɣ������ɶҲû�С�\n",
	}) );
	set("inquiry", ([
		"ǧ������" :    (: ask_me_1 :),
		"��ɽ��" :    (: ask_me_2 :),
		"��֥" :   (: ask_me_3 :),
		"��ҩ" : "����֪��ɶ�������Ұɣ����µ�ҩ�Ҷ���������ʲ��ǧ�����ڡ���֥����ɽ�Ρ����ȵȡ�\n",
	]));

	set("wu_count", 3);
	set("shan_count",  3);
	set("ling_count", 3);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me_1()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return "�Բ����ⶫ��������Ů���ù��ˡ�";

	if (  present("heshou wu", this_player()) )
		return "�Ҳ��Ǹ�����������";

	if (query("wu_count") < 1) return "�Բ����ⶫ��������Ů���ù��ˡ�";

	say("��ͷ��̾��һ�������ȣ�ǧ���������Ů���������ˣ�Ҳ����ʲ����ɫ...\n");
	this_player()->set_temp("marks/��", 1);
	return "������ֻ��һ֧�������εģ���Ů��Ҳ�ò����ˡ�ֻҪһ���ƽ𣬱��������㡣\n";
}
string ask_me_2()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
	return "�Բ����ⶫ��������Ů���ù��ˡ�";

	if (  present("lao shanshen", this_player()) )
	return "�Ҳ��Ǹ�����������";
		
	if (query("shan_count") < 1) return "�Բ����ⶫ����Ů�����ù��ˡ�";
	this_player()->set_temp("marks/ɽ", 1);
	say("��ͷ���૵�����Ů���ѳ����������ⶫ����ֻ������Խ��Խ��������\n");
	return "�ⶫ���ҵ��У�����Ҫ�Ҿ������㣬һ���ƽ𣬲����͹�ǧ����ԣ��Զ��˲��á�\n";
}
string ask_me_3()
{
	object ob;
	
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return  "��֥������ҩ�����Ѳɵ�����������û�С�";

	if (  present("ling zhi", this_player()) )
		return  "��֥������ҩ�����Ѳɵ�����������û�С�";

	if (query("ling_count") < 1) return  "��֥������ҩ�����Ѳɵ�����������û�С�";
	this_player()->set_temp("marks/��", 1);
	say("��ͷ��̧��ͷ�������������´�����һ�������ٺٺ١��ĸ�Ц�˼���...\n");
	return "��֥���Ǻܹ��ص�ࡣ�����������Ҫ�����ƽ𣬲����ۡ�\n";
}
int accept_object(object me, object ob)
{
	object wu, shan, ling;
	if(ob->query("money_id") && ob->value() >= 20000
        && me->query_temp("marks/��") ) {
        ling = new("/d/qilian/obj/lingzhi");
        ling->move(this_player());
        me->delete_temp("marks/��");
        message_vision("��ͷ�Ӵ�Ƥ�Ҵ�����ͳ�һö��֥�ݸ�$N��\n",me);
        return 1;
        }

	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/��") ) {
        wu = new("/d/qilian/obj/fakewu");
        wu->move(me);
        add("wu_count", -1);
	me->delete_temp("marks/��");
	message_vision("��ͷ�Ӵ�Ƥ�Ҵ�����ͳ�һ�ú����ڵݸ�$N��\n",me);
	return 1;
	}
	
        if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/ɽ") ){
        shan = new("/d/qilian/obj/fakeshen");
        shan->move(me);
        add("shan_count", -1);
        me->delete_temp("marks/ɽ");
        message_vision("��ͷ�Ӵ�Ƥ�Ҵ�����ͳ�һ����ɽ�εݸ�$N��\n",me);
        return 1;
        }  
	say(
	"��ͷ��һ�漱æ��Ǯ��������һ��Ц����˵����" + RANK_D->query_respect(ob) + "��������ҩ������˵��С��û��Ū�����ġ�\n");
	return 1;
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
