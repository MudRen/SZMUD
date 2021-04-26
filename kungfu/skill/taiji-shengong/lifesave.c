// Code of ShenZhou
// lifesave.c
// by Marz@XKX
// Ryu modified neilidrop for self lifesave.
//(the higher the lvl should cost more max_neili)
// Fixed the bug in death count, sdong, 12/25/1999

#include <ansi.h>
#include <login.h>

int exert(object me, object target)
{
		  string name, *sname;
		  object deadman, *list;
		  mapping skill_status, learned_status;
		  int i, j, tao_level, tjsg_level, new_exp, neili_drop, sneili_drop, skill_amount;

		  if( !target )
					 return notify_fail("����Ҫ��˭������\n");

		  if( me->is_fighting() || me->is_busy() )
					 return notify_fail("����æ���أ�\n");

                  if ( (tao_level = me->query_skill("taoism", 1)) < 140)
					 return notify_fail("��ĵ�ѧ�ķ���û�޵����������ĳ̶ȣ�\n");

                  if ( (tjsg_level = me->query_skill("taiji-shengong", 1)) < 140)
					 return notify_fail("���̫���񹦻������ߣ�\n");

		  if ( me == target && !me->is_ghost() )
					 return notify_fail("�㻹û�����ò����Ծȣ�\n");
		  else if ( me != target && !target->id("corpse") )
					 return notify_fail("Ҫ������һ��ʬ������˹�������\n");
		  else if ( target->id("corpse") && !target->is_character() )
					 return notify_fail("���ʬ���Ѿ����ã��޷���ת�ˣ�\n");

                  neili_drop = 200 - tjsg_level/2;
                  sneili_drop = 400 - tjsg_level; // this is where the bug from. if tjsg>300, can gain max_neil from lifesave self.
		  if (neili_drop <= 30) neili_drop = 30;

		  if (sneili_drop <= 100) sneili_drop = 100; // add this line to fix the bug, sdong, 8/6/1999
                  if ( me->query( "max_neilie" ) < 3600 ) { neili_drop = neili_drop*2; sneili_drop = sneili_drop*2; }

		  if (target == me)
		  {
					 if (tao_level < 140)
								return notify_fail("��ĵ�ѧ�ķ���û�޵����߳����Źصĳ̶ȣ�\n");

					 if (tjsg_level < 140)
								return notify_fail("���̫���񹦻������ߣ�\n");

					 message_vision( HIW"$N��ϥ���£�Ĭ��̫���񹦣���ʼ��������....\n"NOR, me);
					 tell_object(me, HIW"������Ȧ������һ��������������....\n\n"NOR);

					 if ( me->query("neili") < 1000 || random(tao_level+tjsg_level) < 24 )
					 {
								me->set("neili", 0);
								me->add("max_neili", -10);

								message_vision( HIY"$NͻȻͣ����������Ȼ�����ܵ��������ˣ�\n"NOR, me);

								return notify_fail( HIY"��ϧ���������ã��޷������ȥ�ˣ�\n"NOR );
					 }

					 tell_object(me, HIY"�����Ÿ����죬����õ����е��������Խ��Խʢ....\n"NOR);
					 tell_object(me, HIY"һ������Ե���ӿ����ֱ�����飬��ʹ�ü���������ȥ��\n"NOR);
					 message("vision",
								HIY ""+me->name(1)+"����һ�����������ʧ�ˣ�\n"NOR,
								environment(me), me);

					 me->reincarnate();
					 me->add("neili", -1000);
					 me->add("max_neili", - sneili_drop );

					 learned_status = me->query_learned();

					 if ( mapp(skill_status = me->query_skills()) )
					 {
								sname = keys(skill_status);
								for(i=0; i<sizeof(skill_status); i++) {
										  skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;

										  if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
										  else {
													 if( learned_status[sname[i]]  < skill_amount )
																learned_status[sname[i]] += skill_amount;
													 else {
																learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
																me->set_skill(sname[i], skill_status[sname[i]]+1);
													 }
										  }
                        }
                }

                new_exp = (int)me->query("combat_exp") / 99;
                new_exp = new_exp > 5000 ? 5000 : new_exp;
                me->add("combat_exp", new_exp);
                me->set("qi",1); 
                me->set("eff_qi",1); 
                me->set("jing",1); 
                me->set("eff_jing",1); 
                me->set("jingli", 1);
                me->add("death_count", -1);
                me->add("death_times",-1);
                        
                me->move(REVIVE_ROOM);
                message("vision",
                        "���Ȼǰ�����һ���ˣ���ɫ�Ұף������Ǹմӹײ����������Ƶġ�\n",
                         environment(me), me);

                me->unconcious();

        return 1;       
        
        } else // target is a corpse 
        {
                name = target->query("victim_name"); 
                
                list = users();
                for ( i = 0; i < sizeof(list); i++)
                if ( name == list[i]->name(1) ) break;
        
                if (i == sizeof(list)) 
                        return notify_fail(name+"�Ĺ�겻�ڡ�\n");
                        
                deadman = list[i];      
                if ( !deadman->is_ghost() )
                        return notify_fail(name+"�Ѿ��������,�ò�����ȡ�\n");
                        
                message_vision(
                        HIW "$N����̫���񹦣������İ�"+target->name(1)+"�����Ŵ�Ѩ��\n"
								"$Nһ������ؽ���������ʬ���ڣ�����һ����ҵػ���"+name+"�����֡�\n\n"
								"��һ�ᣬ$N��ͷ��ð�������飬"+target->name(1)+"Ҳ�ƺ�����һ�¡�\n\n"NOR, me);

					 if ( me->query("neili") < 1000 || random(tao_level+tjsg_level) < 24 )
					 {
								me->set("neili", 0);
								me->add("max_neili", -10);
                        
                        message_vision( HIY"$NͻȻͣ����������Ȼ�����ܵ��������ˣ�\n"NOR, me);
                        return notify_fail( HIY"��ϧ���������ã��޷������ȥ�ˣ�\n"NOR );
                } 
                
                me->add("neili", -1000); 
                me->add("max_neili", - neili_drop ); 
                me->receive_damage("qi", 3*neili_drop, "����������ȶ����ˡ�"); 
                me->receive_wound("qi", 2*neili_drop, "����������ȶ����ˡ�"); 

                message_vision( HIY"$NͻȻͻȻ���һ��������������ȫ���ͳ���\n"
                        + "һ�ƻ��ǹ鵽ʬ���ϣ�" + name +"��ʬ�徹Ȼ�λ����Ƶ�վ������"NOR, me);

                tell_object(deadman, HIY "һ��������������㣬ʹ���㼸��������ȥ��\n" NOR);

                message("vision",  
                        HIY"һ���������������"+name+"��ʧ�ˣ�\n"NOR, 
                        environment(deadman), deadman );

                deadman->reincarnate();
                learned_status = deadman->query_learned();

                if ( mapp(skill_status = deadman->query_skills()) )
                {
                        sname = keys(skill_status);
                        for(i=0; i<sizeof(skill_status); i++) {
                                skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;

                                if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
                                else {
                                        if( learned_status[sname[i]]  < skill_amount )
                                                learned_status[sname[i]] += skill_amount;
                                        else {
                                                learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
                                                deadman->set_skill(sname[i], skill_status[sname[i]]+1);
                                        }
                                }
                        }
                }

                new_exp = (int)deadman->query("combat_exp") / 99;
                new_exp = new_exp > 5000 ? 5000 : new_exp;
                deadman->add("combat_exp", new_exp);
                deadman->set("qi",1); 
                deadman->set("eff_qi",1); 
                deadman->set("jing",1); 
                deadman->set("eff_jing",1); 
                deadman->set("jingli",1); 
                deadman->add("death_count", -1);
                deadman->add("death_times",-1);

                deadman->move(environment(me));
                destruct(target);
                deadman->unconcious();

        return 1;       
        }
        

        return 1;
}



// End of File
