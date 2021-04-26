// Code of ShenZhou
// promote.h for fight and get promotion of ؤ��
// created by ???

// Modified by xxx@xkx 01.01 for allowing some npc accept special objects other than ������

/**************************************************************
 All NPCs who need to accept special objects need:

1. define:
#define ACCEPT_SPECIAL_OBJECT
2. declare:
int accept_special_object(object ob, object obj);
3. the npc set:
set("accept_special_object", 1);

If you need an example for this, please read peng.c  ���ϵ��ļ�
***************************************************************/

// Use a macro guard to avoid duplicate accept_special_object() function definition 
// by placing the function's inside a compiler directive.

#ifndef ACCEPT_SPECIAL_OBJECT
#define ACCEPT_SPECIAL_OBJECT

int accept_special_object(object ob, object obj) {return 0;}

#endif

// End of macro guard

int accept_object(object ob, object obj)
{
        object me = this_object();

        // For special NPCs accept special objects
        
        if( obj->query("id") != "qingzhu ling" && query("accept_special_object") )
          return accept_special_object(ob, obj);
        
        // For ������
        
        if( ob->query("family/family_name") != me->query("family/family_name") ) {
                command("say ���Ҳ���ͬһ���ɣ���������������к��ã���");
                return 0;
        }

        if( ob->query("rank") != me->query("rank") ) {
                command("say ���Ұ��б��ݲ�ͬ����û���ʸ�������书���㻹����ͬ���Ĵ�ʦ��ȥ�ɣ�");
                return 0;
        }

        if( obj->query("id") == "qingzhu ling" ) 
        {
                if( obj->query_temp("owner") != ob->query("name") ) {
                        command("say �㲻���������������ˣ�");
                        return 0;
                } else if( obj->query_temp("win_times") < 1 ) {
                        command("say ����δսʤһ��ͬ��ʦ�ֵܣ���������ս�ҵ�������");
                        return 0;
                } else if( obj->query_temp("win_last") ) {
                        command("say ���Ѿ�սʤһλʦ�ֵܺ�ͬ����ʦ�֣�����ֱ���Ҽ���Ҫ������ˣ�");
                        return 0;
                } else {
                        ob->set_temp("fight_ok",1);
                        command("say �ã������������֤һ���书�������Ƿ��ܹ���Ϊһ���ϸ��ؤ��" +
                        chinese_number(ob->query("rank")) + "�����ӡ�");
                        return 1;
                }
        }

        command("shake");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}

int accept_fight(object ob)
{
        object me  = this_object();
        
        if ( !ob->query_temp("fight_ok") ) return 0;

        me->set_temp("challenger", ob);
        ob->delete_temp("fight_ok");
        
        return 1;
}

int chat()
{
        object me = this_object();
        object ob = me->query_temp("challenger");
        object obj;
        int my_max_qi, his_max_qi;

        if( !objectp(ob) ) return ::chat();;
        if (me->is_fighting(ob)) return ::chat();

        me->delete_temp("challenger");

        if (me->is_fighting()) return ::chat();

        if ( !present(ob, environment()) ) return ::chat(); 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                command("say ʦ���书׿������Ϊ�ֺ���֮����������������\n");
                message_vision("\n$Nȡ��������ڱ���ǩ���Լ������ֺ�ݸ�$n��\n\n", 
                                me, ob);

                obj = present("qingzhu ling", me);
                obj->set_temp("win_last", 1);
                obj->move(ob);

                command("say ���Ѿ�սʤ�Һ���һλʦ�ֵܣ�����ֱ���Ҽ���Ҫ������ˣ�");
                return ::chat();
        } 
        else if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                command("say ����ʦ�ܻ��ö����ϰ��������ؤ���ڵ����г���ͷ�أ�\n");
                return ::chat();
        }

        return ::chat();  
}
