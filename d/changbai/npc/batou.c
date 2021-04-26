// Code of ShenZhou
// batou.c

inherit NPC;
int ask_caishen();
string ask_suobogun();


void create()
{
	set_name("�ն���", ({ "heersu", "ba tou" }) );
	set("gender", "����" );
	set("age", 70);
        set("long", "����һλ�뷢�߰׵���Ѯ���ˡ���ͭɫ��Ƥ��������͸�������ǿ��Ŀ�⡣\n");
	set("nickname", "�ϰ�ͷ" );

	set("shen_type", 1);
	set("str", 29);
	set("dex", 26);
	set("con", 24);
	set("int", 19);
	set("attitude","heroism");
       
        set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set("combat_exp", 10000);
        set_temp("apply/attack", 40);
	set_temp("apply/defense", 50);

	set("inquiry", ([
		"name"   : "�Ҿ��Ǻն��գ���������ʲô��ô��",
		"�ɲ�"   : (: ask_caishen :),
                "��"     : (: ask_caishen :),
		"������"   : (: ask_suobogun :),
                "¹��ǥ��"  : (: ask_suobogun :),
	]) );
	setup();
	add_money("silver", 10);
}


int ask_caishen()
{
        string myid = this_player()->query("id");

        command("secret " + myid);
        command("whisper " + myid + " " + 
                " �ɲ��ֽС���ɽ��������һ��ȼ����Σ�յ��е�����ɽ������\n"
                "�������������࣬һ��������ѩ�������Ǹ����׶༪�٣�\n"
                "������ɵ��Σ���ȥ���״�ɽ֮�У�������������ɽ�ݣ�Ѱ��ɽ�ε�\n"
                "�ټ���һ���ҵ�������¹��ǥ�Ӳ��ܽ�֮�����������˵����룡\n");
 
        return 1;
}

string ask_suobogun()
{
        object obj, me = this_player();
        string myid;

        if( (int)me->query_temp("cbshen/ask_gun") > 0 )
                return "�㲻���Ѿ��ʹ����������������ʣ� \n";

        if( present("suobo gun", me) ) 
		return "���������ϲ������������������ʣ� \n";

	if( present("suobo gun", environment()) ) 
	        return "�����ⲻ���� ��Ҫ�Ļ��ͼ��߰ɡ�\n";

        myid = me->query("id");

        switch( me->query_temp("cbshen/blw") ) {
        case 1:
                command("nod " + myid);

                obj = new("/d/changbai/obj/sbgun");
                obj->set("owner", myid);
                obj->move(me);
                message_vision("$N����$nһ" + obj->query("unit") + obj->name() + "��\n", this_object(), me);

                obj = new("/d/changbai/obj/qianzi");
                obj->set("owner", myid);
                obj->move(me);
                message_vision("$N����$nһ" + obj->query("unit") + obj->name() + "��\n", this_object(), me);

                me->delete_temp("cbshen");

                return "�������Ȼ�Ĵ���⡣�����������¹��ǥ�Ӿ��͸���ɣ�\n";
                break;
        case 2:
                command("haha " + myid);
                me->set_temp("cbshen/ask_gun", 2);
                return "����ȥɽ��ү����λǰ����һ�¡�\n";
                break;

        case 3:
                command("disapp " + myid);
                me->set_temp("cbshen/ask_gun", 3);
                return "���˰ɣ��Ⱳ����ͱ�ָ���ˡ�\n";
                break;
        default:
                break;
	}

        me->set_temp("cbshen/ask_gun", 1);
        return "����ȥɽ��ү����λǰ����һ�£���ʾ�Ĵ����ɣ�\n";
}

