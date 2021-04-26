// Code of ShenZhou
int accept_object(object ob, object obj)
{
        if (obj->query("id")!="sheng zhi") {
                command("say �Բ����ⶫ���Ҳ�Ҫ��");
                return 0;
        }
        if (obj->query("applicant")!=ob->query("id")) {
                command("say �⹫���ϵ��˲����㰡��");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("family/family_name") != "����μ�" && !ob->query("dali/employee")) {
                command("say "+RANK_D->query_respect(ob)+"�ͱ��ɲ��޹�ϵ�����Ҵ�����⣿");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("dali/rank")!=2) {
                command("hmm "+getuid(ob));
                command("say "+RANK_D->query_respect(ob)+"�ƺ���ֲ��������������������������ɡ�\n");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("family/family_name")=="����μ�" && ob->query("dali/jobdone")<300) {
                command("say "+RANK_D->query_respect(ob)+"�ҿ��㻹����Ϊ�����������ɣ���ʱ����һ������Ȼ���");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        ob->set_temp("fight_ok3",1);
        command("say �ã���Ȼ�ѵõ�ʥ�ϵ���ɣ����Ǿ�����֤һ���书��");
        remove_call_out("destroying");
        call_out("destroying", 1, obj);
        return 1;
}

void destroying(object obj)
{
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
        object me;
        me=this_object();

        if (!ob->query_temp("fight_ok3")) return 0;

        if (me->is_fighting())
                return notify_fail(me->name()+"ҡͷ����"+RANK_D->query_respect(ob)+"�������ж�Ϊʤ��");

        me->set("qi", me->query("max_qi"));     
        me->set("eff_qi", me->query("max_qi")); 
    me->set("jing", me->query("max_jing")); 
    me->set("eff_jing", me->query("max_jing"));     
    me->set("jingli", me->query("max_jingli"));     

        me->set_temp("challenger", ob);
    add_action("do_kill", "kill");
    ob->delete_temp("fight_ok3");
    return 1;
}

int chat()
{
        object me = this_object();
        object ob = me->query_temp("challenger");
        int my_max_qi, his_max_qi;

    if (!objectp(ob)) return ::chat();
    my_max_qi  = me->query("max_qi");
    his_max_qi = ob->query("max_qi");

    if (me->is_fighting(ob)) return ::chat();
    me->delete_temp("challenger");
    remove_action("do_kill", "kill");
        if (me->is_fighting()) return ::chat();

    if (!present(ob, environment())) return ::chat();

    if (((int)me->query("qi")*100/my_max_qi)<=50) {
                command("say �ã���Ȼ���ֲ��������������ǵ����㡣\n");
                command("say �ã��Ҿʹ���ү�������佫������ϲ���ˣ�\n");
                ob->set("dali/rank",3);
                ob->set("title","������佫");
        return ::chat();
        }

    if (((int)ob->query("qi")*100/his_max_qi)<50) {
                command("say ����"+RANK_D->query_respect(ob)+"��������ǳ��������ʤ�θ�ְѽ��\n");
                return ::chat();
        }
    return ::chat();  
}

int do_kill()
{
    object me= this_object();
    say(me->name()+"�߸߾������ţ��ȵ����������±��䣬����ɱ��!\n");
        return 1;
}
