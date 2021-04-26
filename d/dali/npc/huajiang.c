// Code of ShenZhou
// dali ����
// by acep

inherit NPC;

int do_work();
string ask_me();
string ask_jobdone();

void create()
{
        set_name("����", ({ "hua jiang","huajiang" }) );
        set("gender", "����");
        set("age", 50);
        set("long",
                "����һλ�ϻ�����������������������ݵĹ��������ڴ�����ҿᰮ�軨�����Ĺ����������ӡ�\n");
        set("combat_exp", 3000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("apply/attack", 10);
        set("apply/defense", 10);

        set_skill("blade", 35);
        set_skill("unarmed", 35);
        set_skill("parry", 35);
        set_skill("dodge", 35);
        
        set("inquiry", ([
                "�軨" : "�Ҿ�������ר�Ÿ����ֲ軨�ģ�����󲿷ֵ�����Ʒ�ֶ������ֵġ�",
                "����" : "���������Ӧ��Ϊ�����������µģ����ٵ��Ӿ������⻨԰��ɵ���",
                "�ɻ�" : (: ask_me :),
                "����" : (: ask_jobdone :),
                ]));

        setup();

        carry_object("/d/dali/obj/huachu")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 1);
}

void init()
{
        add_action("do_work", "work");
}

string ask_me()
{
        object me;
        me=this_player();

        if (strsrch(file_name(environment(me)), "/d/dali/garden3") == -1)
                return "Ҫ�ɻ��԰ȥ���Ұɡ�";
        if (me->query("family/family_name")!="����μ�")
                return "�Բ������ʵ�������һ�������������";
        if (me->query_temp("garden_working"))
                return "���Ȱ���ͷ�Ļ������˵�ɡ�";
        if (me->query("dali/rank")==5)
                return "���Ϲ�Ϊ��ү����ô�ܺ���������һ��ɻ��أ����Ǳ��С�Ŀ���Ц�ˡ�";

        if (me->query_temp("worktimes",1) > 7)
                {
                me->apply_condition("work", 50);
                me->set_temp("worktimes", 0);
                return "�����˲��ٻ��ˣ���ȥ��Ϣһ��ɡ�";
                }
        if (me->query_condition("work",1) >0)
                return "�����˲��ٻ��ˣ���ȥ��Ϣһ��ɡ�";
        me->set_temp("garden_working",random(10)+20);
        me->set_temp("working_times",0);
        return "�ü��ˡ�����������Ҫ��������԰�ӣ�����ҳ��������ɡ�";
}

int do_work()
{
        object me, ob, weapon;
        me=this_player();

        if( strsrch(file_name(environment(me)), "/d/dali/garden3") == -1 )
                return notify_fail("�����ڴ���Ժ����ܸɻ");

        if (me->query_temp("garden_working")) {
                if (me->is_busy())
                        return notify_fail("����æ���ء�\n");

                tell_object(me, "��������ȥ�������ࡣ\n");

                if (!objectp(weapon=me->query_temp("weapon"))
                        || weapon->query("id")!="huachu")
                {
                        message_vision("$N����ȥ�β����࣬��������Ǵ̣���Ѫ���ܡ�\n", me);
                        me->add("jingli",-20);
                        me->add("qi", -10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);
                }
                else {
                        message_vision("$N�û������ɵضԸ����Ӳݺ�������\n", me);
                        me->add("jingli",-10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);
                }

                if ( random(me->query("dali/jobdone")) > 650
                && (!present("dang gui", me)) && (!present("da xueteng", me))
                && (me->query("dali/jobdone")) >= 200
                && me->query("combat_exp",1) > 200000 && random(15) == 1 ) {
                        switch (random(3)) {
                        case 0:
                                ob=new(DRUG_D("danggui"));
                                break;
                        case 1:
                                ob=new(DRUG_D("xueteng"));
                                break;
                        case 2:
                                ob=new(DRUG_D("swjing"));
                                break;
                        }
                        message_vision("$N���ĵظ��ŻͻȻ�䷢���Ӳ���������ƺ���ʲô�ر�Ķ�����\n", me);
                        message_vision("$N�������ڳ�һ��"+ob->name()+"��\n", me);
                        ob->move(me);
                }

                if (me->query_temp("working_times")>=me->query_temp("garden_working"))
                {
                        message_vision("������$N���ͷ�������˵�������ˣ����ˣ�����Ļ�͸ɵ�����ɡ�\n", me);
                        message_vision("������$N�����Ĵָ������������㣬�г�һ�ձس�һ���󻨽���\n", me);
                        me->delete_temp("working_times");
                        me->delete_temp("garden_working");
                        me->add("dali/jobdone", 1);
                        me->add_temp("worktimes", 1);
                }
                return 1;
        }
        return 0;
}

int accept_object(object who, object ob)
{
        if (ob->query("id")=="cha hua"
                && ob->query("material")=="wood")
        {
                message_vision("�����˸߲��ҵش�$N����ӹ��軨�����ü��ˣ�����������Ҫ��Ʒ�֣���\n",who);
                command("thank "+getuid(who));
                who->set("dali/jobdone", who->query("dali/jobdone")+1);
//              remove_call_out("destroying");
                call_out("destroying", 1, ob);
                return 1;
        }
}

void destroying(object obj)
{
        destruct(obj);
        return;
}

string ask_jobdone()
{
        object who=this_player();

        if (!who->query("dali/employee"))
                return RANK_D->query_respect(who)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

        return RANK_D->query_respect(who)+"���Ҵ���������֮�У��Ѿ����۹��͵�"+chinese_number(who->query("dali/jobdone"))+"��";
}
