// ����npc
// questionary.c
// creat by shure@tomud.com 2002-04-15

inherit NPC;

#include <ansi.h>

string ask_form();

void create()
{
        set_name("����", ({"ping yi", "ping", "yi"}));
        set("gender", "����");
        set("nickname", HIW"����ʹ��"NOR);
        set("age", 1000);
        set("long",
                "������������ʹ�ߡ�\n"
                "��ÿ�궼�������˼�����һ�⣬ΪһЩ����Ѱ��𰸣�̽����̬���顣\n"
                "���������������"HIR"����"NOR"������\n"
                "�������ͨ�������Լ��ļ�����߸����е����ǡ�\n");

        set("inquiry", ([
                "�ʾ�"       : (: ask_form :),
                "�����ʾ�"   : (: ask_form :),
                "����"       : (: ask_form :),
                "����"       : (: ask_form :),
                "all"       : "�����Ҫ�μӵ���Ļ��ask ping about ���顣",
        ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

string ask_form()
{
        object me;
        object ob;

        me = this_player();
        if( me->query("mud_age") < 1800 )
                return "����ע�����ʮ����������Ϥ����Ϸ��";

        ob = new( "/clone/misc/form" );
        ob->move(me);
        tell_object( me, HIG"�������ص�Ц��Ц��\n"NOR );
        tell_object( me, HIG"����˵��������ҷ���Ҫ������ǹ�������mud�ķ�չ���⡣\n"NOR );
        command( "say " + "���ú���ݡ������ʾ���" ); 
        return "����"HIR" start "NOR + CYN"��ʼ��д����ϸ������ look questionary��";       
}