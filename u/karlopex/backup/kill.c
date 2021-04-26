// Code of ShenZhou
// kill.c
//modified by arthurgu for surrender ,10/99

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, guard_ob;
        string *killer, callname, msg;
        int time;
        time = ((me->query("mud_age"))-(me->query("pktime")));
        
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼ս����\n");

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

//        if(((string)SECURITY_D->get_status(me)=="(immortal)" )
//         && ((string)SECURITY_D->get_status(obj)!="(immortal)" ))
//                return notify_fail("�㲻��ɱ����ˣ�\n");

        if( me->query_temp("last_persuader") == obj->query("id") )
// no chinese input now, will change message
                return notify_fail("�㲻��ɱ����ˣ�\n");

      if( me->query("id") == obj->query_temp("surrender/ownder") )
                return notify_fail("��/���Ѿ�Ͷ����,�����ڲ���ɱ��\n");
            
      if( me->query_temp("surrender/ownder")!=0 )
                return notify_fail("���Ͷ�������ˣ��������Ÿɻ��£�\n");
                
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if( me->query("rided"))
                return notify_fail("��������ɱ������Ų�����ɡ�\n");

        if(obj==me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

       if( (strsrch(file_name(environment(me)), "/d/xiakedao/") >= 0 || strsrch(file_name(environment(me)), "/d/wuguan/") >= 0) && userp(obj) && userp(me))
                return notify_fail(HIR"���ﲻ�ý���PK�ж���\n"NOR);

        //if(userp(obj) && userp(me) && (me->query_condition("pker") > 360 
        //                            || obj->query("mud_age") < 18000) )
        //        return notify_fail("��е�һ˿�ھΣ���ͻȻ����������\n");
                
        //if(userp(obj) && userp(me) && time < 3600 )
          //      return notify_fail("���Ծ�ɱ��̫�أ�������������\n");
                
        callname = RANK_D->query_rude(obj);

        message_vision("\n$N����$n�ȵ�����" 
                + callname + "�����ղ������������һ��\n\n", me, obj);
/*        if(me->query("race")=="����"){
                if(me->query("mute")) 
                        msg = "\n$NͻȻ����$n��˫��ͨ�죬������Ҫ��$p�����أ���\n\n";
                else if(me->query("combat_exp") > obj->query("combat_exp")*2){
		        if(me->query("shen") < -10000)
                       msg = "\n$N����$n����һ�ڣ���"+callname+"������������ʱ��"+RANK_D->query_self_rude(me)+"���쿴�㼫��˳�ۣ������ɣ�����\n\n";
                    else msg = "\n$N����$n�������"+callname+"����Ǻ�"+RANK_D->query_self_rude(me)+"�����֣�������˾ȥ����һ״�ɣ�����\n\n";
		        }
	        else if(obj->query("combat_exp") > me->query("combat_exp")*2){
		        if(me->query("shen") < -10000)
                       msg = "\n$N����$nһ����Ц����"+callname+"������ƽʱҫ������������"+RANK_D->query_self_rude(me)+"��Ҫȡ������������\n\n";
		        else msg = "\n$N�ٺ�һЦ��$n"+callname+"�����似�����㣬���������ƴ����ҲҪ������ʬ��ϣ���\n\n";
		        }
	        else {
		        if(me->query("shen") < -10000)
                     msg = "\n$N����$n�ͺ�һ������"+callname+"������Ľ��������ļ��գ���"+RANK_D->query_self_rude(me)+"������·�ɣ�����\n\n";
		        else msg = "\n$N����$n�ȵ�����" + callname + "���������ѵ����������"+RANK_D->query_self_rude(me)+"����������ɣ���\n\n";
	                }
	        }
	else msg = "\n$N���һ������Ȼ����$n��������Ҫ��$pɱ������\n\n";
	message_vision(msg, me, obj);*/
        if( ! living(obj)
        && obj->query_temp("last_damage_from") != me) 
        me->set_temp("free_rider", 1);

        me->kill_ob(obj);
        
        if( !userp(obj) )
        {
                obj->accept_kill(me);
                if (!obj->is_grpfight())
                        obj->kill_ob(me); 
        }
        else {
                if (!obj->is_killing(me->query("id"))) 
                        me->set_temp("pking/"+obj->query("id"), 1);
                obj->delete_temp("initiator");
                obj->fight_ob(me);
                obj->add_temp("initiate_pk", ({me->query("id")}));
                tell_object(obj, HIR "�����Ҫ��" + me->name() 
                        + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	me->set("last_pk",obj->query("name")+"("+obj->query("id")+")");
        }

        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
