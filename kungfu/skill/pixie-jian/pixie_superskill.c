// Code of ShenZhou
//pixie_superskill.c
//wzfeng@xkx 99 9

#include <ansi.h>
#include <combat.h>
int do_prepare_superskill(string superskill_name,object me,object enemy,int ap,int dp);

void remove_poshensha(object target,int dodge_skill);
int set_perform(object me,string use)
{
	string p1,p2,p3,p4;
	
	if(me->query_temp("pixie_use/1"))
		p1=me->query_temp("pixie_use/1");
	else
		p1="none";
	if(me->query_temp("pixie_use/2"))
		p2=me->query_temp("pixie_use/2");
	else
		p2="none";
	if(me->query_temp("pixie_use/3"))
		p3=me->query_temp("pixie_use/3");
	else
		p3="none";
	if(me->query_temp("pixie_use/4"))
		p4=me->query_temp("pixie_use/4");
	else
		p4="none";
	me->set_temp("pixie_use/1",p2);
	me->set_temp("pixie_use/2",p3);
	me->set_temp("pixie_use/3",p4);
	me->set_temp("pixie_use/4",use);
	return 1;
}

void checking_pixieflg(object me,object enemy)
{
	string perform_name;
	perform_name=me->query_temp("pixie_use/4");

	me->set_temp("pixie_noop",1);
	if( wizardp(me) &&me->query("env/pixie_test"))
	{
		printf(HIC"��һ����ɱ��������%s\t",me->query_temp("pixie_use/3"));
		printf(HIC"��ǰʹ�õı�ɱ����%s\n"NOR,me->query_temp("pixie_use/4"));
	}
		if(me->query_skill_mapped("sword") != "pixie-jian"
		||me->query_skill_mapped("dodge") != "pixie-jian"
			||me->query_skill_mapped("parry") != "pixie-jian"
			||!objectp(me->query_temp("weapon")))
	{
		if( wizardp(me) &&me->query("env/pixie_test"))
		printf(HIC"change skills, del all\n");
		   enemy->delete_temp("pixie_times");
		   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");
		   remove_call_out("checking_pixieflg");

       return ;

	}



	if( !living(me) || me->is_ghost()|| !me->is_fighting())
        {
		if( wizardp(me) &&me->query("env/pixie_test"))
		printf(HIC"if( !living(me) || me->is_ghost()|| !me->is_fighting())\n");
                  if ( enemy )
			   enemy->delete_temp("pixie_times");
			   me->delete_temp("pixie_noop");
   			   me->delete_temp("pixie_use");
			   me->delete_temp("pixie_superskill");
			   me->delete_temp("pixie_performtime");
			   remove_call_out("checking_pixieflg");
			   return;
 
        }

   	       if( !living(enemy) || enemy->is_ghost()
			   || !enemy->is_fighting())
        {
			   	if( wizardp(me) &&me->query("env/pixie_test"))
			   printf(HIC"if( !living(enemy) || enemy->is_ghost()|| !enemy->is_fighting())\n");
                  if ( enemy )
			   enemy->delete_temp("pixie_times");
			   me->delete_temp("pixie_noop");
   			   me->delete_temp("pixie_use");
			   me->delete_temp("pixie_superskill");
			   me->delete_temp("pixie_performtime");
			   remove_call_out("checking_pixieflg");
			   return;
 
        }

		   /////////////////////////////////////////////////////////////////////
	if(me->query_temp("pixie_performtime")>0)
	{
		
	me->add_temp("pixie_performtime",-1);
			switch (perform_name)
		   {
		   case "pixie-cimu":
			   {
				   
				   if(me->query_temp("pixie/guimei"))
				   me->set_temp("pixie_superskill/poshensha",1);
				   me->set_temp("pixie_superskill/duoming",1);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
				   {
				   printf(HIY"Perform cimu �ɹ���Set �ɹ� posheshan 1\n"NOR);
				   printf(HIY"Perform cimu �ɹ���Set �ɹ� duoming 1\n"NOR);
				   }
		
			   }
			   break;
   		   case "pixie-ciwan":
			   {
				   if((string)me->query_temp("pixie_use/3")=="pixie-cimu"
					&&(string)me->query_temp("pixie_use/4")=="pixie-ciwan"
				   &&(me->query_temp("pixie_superskill/poshensha")>=1))
				   {
				   me->set_temp("pixie_superskill/poshensha",2);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
   				   printf(HIY"ciwan �����ɹ���Set posheshan 2\n"NOR);
				   }
				   else
				   {
 				   if((string)me->query_temp("pixie_use/3")=="pixie-cizu"
					  &&(string)me->query_temp("pixie_use/4")=="pixie-ciwan"
				   &&(me->query_temp("pixie_superskill/duoming")>=2))
				   {
				   me->set_temp("pixie_superskill/duoming",3);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
   				   printf(HIY"ciwan �����ɹ���Set duoming 3\n"NOR);
				   }
				   else
				   {
					    //me->delete_temp("pixie_noop");
   						me->delete_temp("pixie_use");
					    me->delete_temp("pixie_superskill");
					    me->delete_temp("pixie_performtime");
			 		    if( wizardp(me) &&me->query("env/pixie_test"))
						{
      				   printf(HIM"ciwan ����ʧ�ܣ�Set duoming 0\n"NOR);
      				   printf(HIM"ciwan ����ʧ�ܣ�Set posheshan 0\n"NOR);
						}
				   //////////////////////////////////////////////////////////////
				   }
				   	if( wizardp(me) &&me->query("env/pixie_test"))
					{
					printf(HIC"������ɻ�%d\n"NOR,me->query_temp("pixie_superskill/duoming"));
					printf(HIC"��������ɱ���%d\n"NOR,me->query_temp("pixie_superskill/poshensha"));
					}
				   }
			   }
			   break;
			case "pixie-cizu":
			   {
				   //////////////////////////////////////////////////////////////
  				   if((string)me->query_temp("pixie_use/3")=="pixie-cimu"
					  &&(string)me->query_temp("pixie_use/4")=="pixie-cizu"
				   &&(me->query_temp("pixie_superskill/duoming")>=1))
				   {
				   me->set_temp("pixie_superskill/duoming",2);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
   				   printf(HIY"cizu �����ɹ���Set duoming 2\n"NOR);
				   }
				   else
				   {
   						   me->delete_temp("pixie_use");
						   me->delete_temp("pixie_superskill");
						   me->delete_temp("pixie_performtime");
						   if( wizardp(me) &&me->query("env/pixie_test"))
      				       printf(HIM"cizu ����ʧ�ܣ�Set duoming 0\n"NOR);
				   }

			   }
			   break;
			}
	
	}
	else
	{
			   if( wizardp(me) &&me->query("env/pixie_test"))
			   	printf(HIC"Perform time =0 del all flag\n"NOR);
   			   me->delete_temp("pixie_use");
			   me->delete_temp("pixie_superskill");
			   me->delete_temp("pixie_performtime");
	}
	remove_call_out("checking_pixieflg");
	call_out("checking_pixieflg", 1, me, enemy, perform_name);
	return;
}
//use pixie-superskill
int do_prepare_superskill(string superskill_name,object me,object target,int ap,int dp)
{
	string perpare_msg;
	int dodge_skill,damage,cizu_busy;
	object weapon;
	weapon=me->query_temp("weapon");
	dodge_skill=target->query_skill("dodge");
	if(dodge_skill<=0) dodge_skill=0;
	perpare_msg="";
	if(me->query("dex")>25&&me->query("dex")>target->query("dex"))
			cizu_busy=me->query_dex();
		else
			cizu_busy=me->query_dex()/2;
	switch(superskill_name)
	{
	case "pixie-cizu":
		{
		   if((string)me->query_temp("pixie_use/3")=="pixie-cimu"
			  &&(string)me->query_temp("pixie_use/4")=="pixie-ciwan")
			  
			  if(me->query_temp("pixie_superskill/poshensha")>=2
				&&me->query_temp("pixie_performtime")
				&&me->query("neili")>300&&me->query("jingli")>300
					&&me->query_temp("pixie/guimei"))
				
			
				{

					perpare_msg += HIB "\n$N�͵Ĵ߶�����а������Ӱ����$n����ģ����˫���ܴ�������ӽ�$n��\n"NOR;

					perpare_msg += HIB "$NͻȻһ����������"+weapon->query("name")+"����$n˫��ҪѨ��\n"NOR;

					if(me->query("qi")<me->query("max_qi")/3)
					ap=ap*3/2;
			        if( random(ap+dp) < dp )
					{
						perpare_msg += HIG "$nֻ������������Ʈ������֪��$NϮ������������˫���أ�����ˣ�����������С�\n"NOR;
			            me->start_busy(3 + random(3));
					}
					else
					{
    					perpare_msg += HIR "$n֪����ǰ����������֪�����²��룬������ֻ��˫��һ�飬�ѱ�$N����ҪѨ����������ʧȥ֪����\n"NOR;	
						perpare_msg += HIY "$N���о����ʢ���⡸��Ŀ�������󡹡����㡹����һ���ǳɡ�\n"NOR;	
						perpare_msg += HIR "$n��ʱȫ��ʧȥ֪������Ҳ�������á���\n"NOR;	
						perpare_msg += HIB "$N����һЦ��չ�����Ȱ�����������ص�ԭ�����ƺ���δ�ƶ���\n"NOR;	
						target->add_temp("apply/dodge",  -dodge_skill);
						target->set_temp("pixie/cizu",1);
						target->set_temp("cannot_move",1);
						target->set_temp("cannot_move_msg","��˫��ҪѨ�����У����ﻹ���ƶ��벽��");

						target->add_temp("pixie_times/cizu",1 );
						target->set_temp("pixie_bisha/poshensha",1);
						target->start_busy(me->query_skill("pixie-jian",1)/15);
						target->add("eff_qi",-(random((int)me->query_skill("pixie-jian"))*4/3));
						me->start_call_out( (: call_other, __FILE__, "remove_poshensha",target, dodge_skill :), cizu_busy);
						me->start_busy(1 + random(1));
					}


					me->add("neili", -(100+random(100)));
					me->add("jingli", -(100+random(100)));
					me->delete_temp("pixie_useperform");
					me->delete_temp("pixie_noop");
   				   me->delete_temp("pixie_use");
				   me->delete_temp("pixie_superskill");
				   me->delete_temp("pixie_performtime");
					
					message_vision(perpare_msg, me, target);
					return 1;

				}
		}
		break;
	case "pixie-cixin":
		{

		   if((string)me->query_temp("pixie_use/2")=="pixie-cimu"
			  &&(string)me->query_temp("pixie_use/3")=="pixie-cizu"
			  &&(string)me->query_temp("pixie_use/4")=="pixie-ciwan"
				&&me->query_temp("pixie_superskill/duoming",3)
				&&me->query_temp("pixie_performtime")
				&&me->query("neili")>500&&me->query("jingli")>500
					&&me->query_temp("pixie/guimei"))
				{
					
					perpare_msg += HIB "\nɲ�Ǽ�$N��Ӱ�������쳣����$n����ģ����ȫ������֮�ʣ�ʩչ����а���������ġ�������\n"NOR;
					perpare_msg += HIB "$N��ҡ��֫����ӰƮ�����û�������������Ӱ��ͻȻһӰ�ɳ���Ϯ��$n��\n"NOR;
			        if(random(ap+dp)<dp||(random(7)==0))

					{
						perpare_msg += HIG"$n���þ������棬֪����$Nʩչ����ɱ�ţ��Ͻ���ס���ƣ�һ��б�������յıܿ���һ�С�\n" NOR;
						me->start_busy(3 + random(5));
						me->delete_temp("pixie_performtime");
					}
					else
					{
   						
						perpare_msg += HIR "$n֪����ǰ������������֪���²���������Ŀ�һ�ۣ��ѱ�$N���С�\n"NOR;	
						perpare_msg += HIY "$N���о����ʢ���⡸��Ŀ��,�����󡹡����㡹�����ġ�����һ���ǳɡ�\n"NOR;	
						perpare_msg += HIR "��ʱһ��Ѫ����$n�Ŀڱ��������������\n"NOR;	
						perpare_msg += HIB "$N����һЦ��չ�����Ȱ����������Ѫ�������ȥ��ɲ�Ǽ�ص�ԭ����\n"NOR;	
						
						damage=me->query_skill("pixie-jian",1)*(random(5)+5);
						if(me->query_skill("pixie-jian",1)>400)
						damage=damage*2;

						target->add_temp("pixie_times/cixin",1 );
						if(target->query("qi")<target->query("max_qi")/3)
							target->set("eff_qi",0);
							else
						{
						target->add("eff_qi",-damage*(2+random(2)));
						}
						if(target->query("eff_qi")<=0)
							target->unconcious();
						if(target->query("qi")<=0)
							target->unconcious();
						if(target->query("jingli")<=0)
							target->unconcious();
						me->start_busy(2 + random(2));
					}
					me->add("neili", -(100+random(200)));
					me->add("jingli", -(100+random(200)));
					me->delete_temp("pixie_useperform");
					me->delete_temp("pixie_noop");
   				   me->delete_temp("pixie_use");
				   me->delete_temp("pixie_superskill");
				   me->delete_temp("pixie_performtime");
					
					message_vision(perpare_msg, me, target);
					return 1;

				}
		}
		break;

	}
	return 0;

}


void remove_poshensha(object target,int dodge_skill)
{
		        if( !target ) return;
			target->add_temp("apply/dodge",  dodge_skill);
			target->delete_temp("pixie/cizu");
			target->delete_temp("pixie_times/cizu");
			target->delete_temp("pixie-bisha/poshensha");
			target->delete_temp("cannot_move");
			target->delete_temp("cannot_move_msg");

	        if(target->is_fighting() )
				message_vision(HIG"$N���ڳ忪����Ѩ����˫���ж��ָ�������\n"NOR, target);
			
			return ;

}




