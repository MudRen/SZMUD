int accept_object(object ob, object obj)
{
        if (obj->query("id")!="gongji biao") {
                command("say �Բ����ⶫ���Ҳ�Ҫ��");
                return 0;
        }
        if (obj->query("applicant")!=ob->query("id")) {
                command("say �Ȿ���������Ǵ�����͵���ģ�");
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

        if (ob->query_temp("dali/uprank")!=1) {
                command("hmm "+getuid(ob));
                command("say �Ȿ���������Ǵ�����͵���ģ�");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("family/family_name")=="����μ�" && ob->query("combat_exp")< 6400000) {
                command("say "+RANK_D->query_respect(ob)+"�㾭��̫�������ͳ��������");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        ob->set_temp("arrest_yanqing",1);
        command("thumb");
		command("sigh");
		command("say ���Ҵ����һֱ��̩��,��û�뵽�ҶμҾ�����������������ͽ�������ܽ���ɱ������ӹٽ�����");
        remove_call_out("destroying");
        call_out("destroying", 1, obj);
        return 1;
        }
        
        
       
void destroying(object obj)
{
        destruct(obj);
        return;
}

