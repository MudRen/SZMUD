// Code of ShenZhou
// surrender.c
// arthurgu 1999/10

#include <ansi.h>

inherit F_CLEAN_UP;

void waittime1( object me ) ;
void waittime2( object me ) ;

int main(object me, string arg)
{     
	object ob,obj;
	object op;
	if ( !objectp(op = find_object("/d/city/npc/aqingsao")) )
                        op = load_object("/d/city/npc/aqingsao");

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("����˭Ͷ����\n");

        if( !obj->is_character() )
                return notify_fail("�����һ�㣬�ǲ��������\n");

        if( !userp(obj) )
                return notify_fail("��ֻ�������Ͷ����\n");

	if( me->is_busy())
		return notify_fail("�㻹��æ����\n");
		
	if( me->query_temp("surrender_not")==1)
		return notify_fail("�����ڲ�������Ͷ������һ�������ԣ���\n");	
	
	if( !me->is_fighting() )
		return notify_fail("Ͷ��������û�����ڴ��㰡....��\n");
	
	ob = me->query_temp("last_opponent");
	if( random(3)==0)
	     {
		message_vision( HIC "\n $N��$n���ģ�����$n����˵����"
			+ RANK_D->query_rude(me) + "�ϻ���˵����������\n" NOR, me, ob);
		me->set_temp("surrender_not",1);
		 call_out("waittime1", 60 , me );	
			
		return 1; }
		
	else if( random(3)!=0)
	     {
	       me->set("shen", 99*(int)me->query("shen")/100 );
	       if( (int)me->query("combat_exp") <= 5000 )
                me->add("combat_exp", 0 );
        else
                me->add("combat_exp", -(int)me->query("combat_exp")/5000 );
                
                me->set_temp("surrender",1);
	        me->set_temp("surrender/ownder", ob->query("id"));                 
       	
	        me->remove_all_enemy();
	        ob->remove_killer(me);
	        me->remove_killer(ob);
	        message_vision( HIW "\n$N��$n�������ĵ����������ˣ������ˣ���Ͷ��....��\n" NOR, me,ob );
	        message_vision( HIC "$n��м��Ʋ��Ʋ�죬��$N˵�������������������ҽ���ͷ���һ���Ժ�ɵ�С�ģ�����\n\n" NOR, me,ob );
	        CHANNEL_D->do_channel(op,"rumor",""+me->query("name") +"̰����������"+ob->query("name") +"Ͷ���ˣ�\n");
	        call_out("waittime2", 1000 , me );	
	  
	        
	      }
		return 1;
}


void waittime1( object me )
{
  me->delete_temp("surrender_not");
  
}

void waittime2( object me)
{ 
  me->delete_temp("surrender/ownder");
  message_vision("��ָ���һЩ��Ͷ�������͵����ġ�\n", me);
  
}


int help(object me)
{
  write(@HELP
ָ���ʽ : surrender <id>
 
���ָ����������л��������Ͷ������ֹս������Ͷ�����㽫��һ������ʧ��
 
HELP
    );
    return 1;
}
 
