// Code of ShenZhou
// /d/hangzhou/npc/du.c  �����
// by aln  2 / 98
// modified by aln 4 / 98

inherit NPC;

#include <ansi.h>

int auto_throw();
int come_killer();
string ask_job();
       
void create()
{
        set_name("�����", ({ "du dajin", "du" }));
        set("gender", "����");
        set("age", 45);
        set("long", 
"���������ɵ��׼ҵ��ӣ�ȭ�Ƶ����������൱���衣\n"
"����һ��������ڣ���һ��������������ʮ��ö���ڡ�\n"
"��˽�����������һ����ţ���������ܡ�\n");
        set("shen_type", 1);
        set("combat_exp", 220000);

        set("str", 25);
        set("int", 10);
        set("con", 20);
        set("dex", 20);
 
        set("max_qi", 800);
        set("max_jing", 400);
        set("max_neili", 800);
        set("neili", 800);
        set("jiali", 50);
        set("score", 10000);

        set_temp("apply/armor", 30);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("throwing", 100);

        set_skill("hunyuan-yiqi", 80);
        set_skill("shaolin-shenfa", 80);
        set_skill("banruo-zhang", 80);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "banruo-zhang");
        map_skill("strike", "banruo-zhang");

        prepare_skill("strike", "banruo-zhang");

        set("chat_chance", 3);
        set("chat_msg",({
                (: come_killer :)
        }));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_throw :),
        }) );

        set("inquiry", ([
                "����" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

        setup();

        carry_object("/clone/anqi/feibiao")->set_amount(3);
}

int come_killer()
{
        object ob, room;

        if( is_fighting() || is_busy() ) return 1;

        if( !(room = environment()) ) return 1;

        if( base_name(room) != "/d/hangzhou/biaoju" ) return 1;

        if( ob = present("mengmian ren", room) ) {
                if( !ob->is_fighting(this_object()) )
                        ob->kill_ob(this_object());
                return 1;
        }
        
        ob = new(__DIR__"figure");
        ob->move(room);
        ob->set_leader(this_object());
        say("ͻȻһ�������˿첽���˹�����" + name() + "�ȵ��������������Ľ�������ļ��գ�\n");
        command("go enter");
        command("!!!");
        ob->kill_ob(this_object());
        return 1;
}

string ask_job()
{
        object obj, wage, me = this_player();
        mapping myfam;
        int bonus;

        if( is_fighting() || is_busy() )
                return "����æ�š�";

        if( base_name(environment()) != "/d/hangzhou/biaoju" ) {
                call_out("do_back", 1);
                return "���Ҳ�������˵�ɡ�";
        }

        if( !mapp(myfam = me->query("family")) )
                return RANK_D->query_respect(me) + "�������ֵ��ӣ�ˡ��¼�á�";

        if( myfam["family_name"] != "������" )
                return RANK_D->query_respect(me) + "�������ֵ��ӣ�ˡ��¼�á�";

        if( myfam["generation"] > 37 )
                return RANK_D->query_respect(me) + "��������������������ɡ�";

        if( me->query_condition("lmjob") )
                return RANK_D->query_respect(me) + "�Ѿ���¼���ˡ�";

        if( me->query_temp("lmjob/ok") ) {
                bonus = (int)me->query("combat_exp") / 10000;
                bonus += random(bonus);
                wage = new("/clone/money/silver");
                wage->set_amount(bonus);
                wage->move(me);
                message_vision("$Nת���ó�һ������ݸ�$n��\n", this_object(), me);

                me->delete_temp("lmjob");
          //      me->add("combat_exp", bonus);
                return RANK_D->query_respect(me) + "�����ˡ�";
        }

        if( !(obj = present("tuijian xin", me)) )
                return RANK_D->query_respect(me) + "û�������·��ɵ��Ƽ��ţ�ˡ��¼�á�";

        if( (string)obj->query("owner") != me->query("id") )
                return "����Ƽ��Ų���Ϊ��" + RANK_D->query_respect(me);

        message_vision("$N����$nһ���Ƽ��š�\n", me, this_object());
        destruct(obj);

        me->apply_condition("lmjob", 10 + random(10));
        command("nod");

        return "̫���ˣ������������Ҫһ�����ֵ��Ӵ����书��";
}

void do_back()
{
        say("���������ææ�뿪�ˡ�\n");
        move("/d/hangzhou/biaoju");
        say("������첽���˹�����\n");
}

#include "/clone/npc/auto_throw.h";
