//Cracked by Yujie
inherit NPC;

int ask_set();

void create()
{
        set_name("�����̴�", ({ "shi cong","shicong"}) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long","����ר����ѡ�����̺�ְ���������Ů��\n");
        set("str", 12);
        set("dex", 20);
        set("con", 13);
        set("shen_type", 0);
        set("combat_exp", 200);
        set("max_qi", 200);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
            "set" : (: ask_set :),
            "here" : (: ask_set :),
        ]) );
        setup();
}

int ask_set()
{
        object me = this_player();
        
        if ( !stringp(me->query("clbpos")) )
        {	message_vision(query("name")+"����$Nҡ��ҡͷ��˵�����㲻�Ǳ�����������Ҳ������㡣\n",me);
        	return 1;
        }
        
        write("�̴�������͵���\n");
        write("���������Լ��ķ�����������ܶ����顣\n");
        write("�����Լ�װ���Լ��ķ��䣨��modifyд������������\n");
        write("���������루invite������������˽�����档\n");
        write("������������������Լ������Ƿ�����ս������nofight��canfight���ã���\n");
        write("���Լ��ķ����������԰��ĵ�����˯����û�б������������㡣\n");
        
        return 1;
}
