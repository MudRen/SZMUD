// Code of ShenZhou
// Summer, 10/16/96. 

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();

void create()
{
	set_name("���ϰ�", ({"dian laoban", "laoban"}));
	set("long",
		"����һλ���Ͱ�С���������ˡ������ڹ�̨�ᲦŪ�����̡�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 4000);
	set("score", 100);

	set("inquiry", ([
		"ǧ������" :    (: ask_me_1 :),
		"��ɽ��" :    (: ask_me_2 :),
		"��֥" :   (: ask_me_3 :),
	]));

	set("wu_count", 10);
	set("shan_count",  10);
	set("ling_count", 1);
	setup();
}

string ask_me_1()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return "�Բ��𣬱��������޻���";

	if (  present("heshou wu", this_player()) )
		return "�Ҳ��Ǹ�����������";

	if (query("wu_count") < 1) return "�Բ��𣬱��������޻���";

	say("���ϰ�̧��ͷ�������������´�����һ�������ٺٺ١��ĸ�Ц�˼���...\n");
        
	this_player()->set_temp("marks/��", 1);
	return "ǧ���������������ʱ��û�У�ȴ��һ֧�������εģ�ֻҪһ���ƽ𣬲����ۡ�\n";
}
string ask_me_2()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
	return "�Բ��𣬱��������޻���";	

	if (  present("lao shanshen", this_player()) )
	return "�Ҳ��Ǹ�����������";
		
	if (query("shan_count") < 1) return "�Բ��𣬱��������޻�";
	this_player()->set_temp("marks/ɽ", 1);
	say("���ϰ�̧��ͷ�������������´�����һ�������ٺٺ١��ĸ�Ц�˼���...\n");
	return "��ɽ��������ﵹ��һ֧��ֻҪ��ʮ�����ӣ������ۡ�\n";
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
	say("���ϰ�̧��ͷ�������������´�����һ�������ٺٺ١��ĸ�Ц�˼���...\n");
	return "��֥���Ǻܹ��ص�ࡣ�����������Ҫ�����ƽ𣬲����ۡ�\n";
}
int accept_object(object me, object ob)
{
	object wu, shan, ling;
	if(ob->query("money_id") && ob->value() >= 5000
        && me->query_temp("marks/ɽ") ){ 
	shan = new("/d/qilian/obj/shanshen");
        shan->move(me);
        add("shan_count", -1);
	me->delete_temp("marks/ɽ");
        message_vision("$N�ӵ��ϰ崦����һ����ɽ����\n",me);
	return 1;
	}


	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/��") ) {
        wu = new("/d/qilian/obj/shanshen");
        wu->move(me);
        add("wu_count", -1);
	me->delete_temp("marks/��");
	message_vision("$N�ӵ��ϰ崦����һ�ú����ڡ�\n",me);
	return 1;
	}
	
	if(ob->query("money_id") && ob->value() >= 20000
        && me->query_temp("marks/��") ) {
        ling = new("/d/qilian/obj/lingzhi");
        ling->move(this_player());
	me->delete_temp("marks/��");
        message_vision("$N�ӵ��ϰ崦����һ֧��֥��\n",this_player());
        return 1;
	}

          
	say(
	"���ϰ�һ�漱æ��Ǯ��������һ��Ц����˵����" + RANK_D->query_respect(ob) + "��������ҩ������˵��С��û��Ū�����ġ�\n");
	return 1;
}
void unconcious()
{
        message_vision("\nͻȻ��ֻ�����ϰ�����������̨��һ�����ţ����˽�ȥ���������
�߰��������ˡ�\n",
                this_object());
        destruct(this_object());
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
