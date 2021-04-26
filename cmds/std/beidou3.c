// Code of ShenZhou
// beidou3.c
// �������
// by sdong 10/10/98

inherit F_CLEAN_UP;

#include <ansi.h>
#include <skill.h>



inherit F_SSERVER;
string *position = ({
					 "��Ȩ","����","���","����","���","����","ҡ��"
});

string *sword = ({
	"̤���ţ���ƫ�棬������˼�����һ�������ޱȵġ��ֻ�������������ʵ�������д�ȥ��",
	"ʹһ�С���������������������Ʈ�����н�����ʵʵ�ó����㺮��������С�",
	"����һת����Ȼһʽ���ɨҶ����������콣Ӱ��Ю�ž�����ǰɨȥ��",
	"���쳤Ц������ƮȻ�����ڰ��������һ����һʽ�����ʹ��������ػ�����С�",
	"�������Ž���������̤��һ�С������롱����б�̡�",
	"��ǰ��ȥһ�󲽣�ʹ����̽�������������н����һ������Ѹ�����׻�����",
	"����һ������һʱ�������仨�������ó���㽣����ƮȻ�̳���",
	"���н�һָ���������࣬һʱ������Į�����������������",
	"��������Ʈ��ͻȻһת��ͷ�½��ϣ����ս���һ�С���׹��������������Ϣ�ع�����",
	"���һ����һ�С��׺羭�졹��������㻮��һ����Բ�����¡�",
	"��Ȼ���θ߸�Ծ��ʹ�����˼����ġ������н��ó����컨�꣬Ѹ�����������"
});

string *zhen =  ({
	"������󷨹����ƶ����������಻����˲�佫����Χ�����ġ�",
	"����������ƺ��ǰ�������������ӣ������ۻ����ң������ʧ��",
	"ֻ��������󰵺����а���֮�������˲������������ϵ������޷졣",
	"�������Խ��ԽС�����ν������˳�һ��������룬��������Ϣ֮�С�"
});


int check_ob(object ob,object me);
void start_beidouzhen(object ob, int mypos,int beidou_time );
int beidouzhen(object me);
int halt_beidouzhen(object me);
int do_beidouzhen(string arg);
int beidouzhen(object me);
int halt_beidou(object me);
int stop_beidou();

void create() { seteuid(getuid()); }


int main(object me, string arg)
{
		  object enemy;
		  int beidou_time,i,mypos=0,power,bd_power;
		  object here;
		  string name1,name2,enemy_id;
		  object ob1,ob2,ob3;

		  if( this_player()->is_busy() )
		  {
		  		return notify_fail("����æ���أ�\n");
		  }

		  here = environment( this_player() );

		  if( !arg || sscanf(arg, "%s %s %s", enemy_id,name1,name2)!=3 )
					 return notify_fail("beidou3 enemy friend1 friend2\n");

		  if( !(enemy = present(enemy_id, here) ) )
		  {
				return notify_fail(enemy_id+"�������\n");
		  }

		  if( enemy->query("race") != "����" )
		  {
				return notify_fail("ɱ������ţ����\n");
		  }

		  if( enemy->query("family/family_name") == "ȫ���" )
		  {
				return notify_fail("ͬ����У�\n");
		  }


		  if( !(ob1 = present(name1, here ) ) )
		  {
				return notify_fail(name1+"�������\n");
		  }

		  if( ob1->is_busy() )
		  {
		  		return notify_fail(name1+"��æ���أ�\n");
		  }
		  
		  i = check_ob(ob1,me);
		  if(  i !=1) return i;

		  if( !(ob2 = present(name2, here) ) )
		  {
				return notify_fail(name2+"�������\n");
		  }

		  if( ob2->is_busy() )
		  {
		  		return notify_fail(name2+"��æ���أ�\n");
		  }

		  i = check_ob(ob2,me);
		  if(  i !=1) return i;

		  if( name1 == me->query("id") ||   name2 == me->query("id")  )
		  {
				return notify_fail("��һ�����ã��㲻��������ɣ�\n");
		  }

		  if( name1 == name2 )
		  {
				return notify_fail(name1 + "����������ɣ�\n");
		  }


		  power = me->query("force") + ob1->query("force")+ob2->query("force");
		  power += me->query("sword") + ob1->query("sword")+ob2->query("sword");
		  power += me->query("str") + ob1->query("str")+ob2->query("str");
		  power += me->query("dex") + ob1->query("dex")+ob2->query("dex");
		  bd_power = me->query("beidou-zhenfa") + ob1->query("beidou-zhenfa")+ob2->query("beidou-zhenfa");
		  power = power / 140/2;
		  bd_power /= 70/5;
		  power *= bd_power;

		  if(power>50)power=50;
		  if(power,15)power=15;


		  start_beidouzhen(me,0,power);
		  start_beidouzhen(ob1,1,power);
		  start_beidouzhen(ob2,2,power);

		  here->set_temp("ob1",me->query("id"));
		  here->set_temp("ob2",ob1->query("id"));
		  here->set_temp("ob3",ob2->query("id"));

		  message_vision(HIR"\n$N��$n�ȵ���" + RANK_D->query_rude(enemy) + "��һ��Ϊ�����������챾��Ҫ�����е�����������\n"NOR, me, enemy);
		  me->kill_ob(enemy);
		  ob1->kill_ob(enemy);
		  ob2->kill_ob(enemy);
		  enemy->kill_ob(me);
		  enemy->kill_ob(ob1);
		  enemy->kill_ob(ob2);
		  message_vision(HIM"$NͻȻ�����ƶ���������ȫ�������ռλ�ã����ǰڵġ���������󷨡�\n\n"NOR, me);
		  return 1;
}


int check_ob(object ob,object me)
{
	string ob_name;
	object weapon;
	float exp_diff;

			  if( !objectp(ob) )
			  {
					 return notify_fail("��ϧû������ˡ�\n");
			  }
				  ob_name = ob->query("name");

				  if ( !present( ob->query("id"), environment(me) ) )
				  {
					 return notify_fail("��ϧ"+ob_name+"�������\n");
				  }

				  if ( ob->query("family/family_name") != "ȫ���" )
				  {
					 return notify_fail("��ϧ"+ob_name+"����ȫ����ӣ����ᡸ������󡹡�\n");
				  }


				  if ( ob->query_skill("quanzhen-jian",1) <60 || ob->query("combat_exp",1)<50000 ||
						ob->query_skill("dodge") <60
					  )
				  {
					 return notify_fail("��ϧ"+ob_name+"�书̫����ᡸ������󡹡�\n");
				  }

				  exp_diff = (float)( ob->query("combat_exp" ) - me->query("combat_exp") ) / (float)me->query("combat_exp");

				  if( exp_diff > 0.3 || exp_diff < -0.3 )
				  	 return notify_fail("��ϧ"+ob_name+"�书������̫�󣬲��ܹ��ڡ�������󡹡�\n");

		 return 1;
}

void start_beidouzhen(object ob, int mypos,int beidou_time )
{
			ob->set_temp("pending/beidou", 1);
			ob->set_temp("beidou_time", beidou_time*2);
			ob->set_temp("bd_pos", mypos);
			ob->set_temp("bd_power",beidou_time);
			ob->start_busy((: beidouzhen :), (:halt_beidou:));
}




void destruct_me(object me)
{
	if(me)
		destruct(me);
}

void check_leaving(object me)
{
	string name = me->query("id");

	 if( !userp(me) )
		{
		 object enemy = offensive_target(me);
		 if( !objectp(enemy) && !me->is_busy() && !me->is_fighting() )
		 {
			 message_vision(HIY"\n$N���˸�鮵���ƶ���ȸ����ˣ�˵��Ϳ첽�뿪�ˡ�\n"NOR, me);
			 call_out("destruct_me",10,me);
			 return;
		  }

		  call_out("check_leaving",5,me);
	  }
}

int beidouzhen(object me)
{
		  object  where = environment(this_player());
		  int beidou_time = (int)me->query_temp("beidou_time");
		  object room, obj,enemy,weapon;
		  int cost, bonus,mypos=me->query_temp("bd_pos");
		  int power;
		  object ob1,ob2,ob3,ob4,ob5,ob6,ob7;


		  if( !(room = environment(this_player())) )

		  {

				  if(!objectp(weapon = me->query_temp("weapon"))

						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
						}
				else
					message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);

				me->remove_all_enemy();

				me->delete_temp("pending/beidou");
				me->delete_temp("beidou_time");
				me->delete_temp("bd_pos");
				me->delete_temp("bd_power");
				call_out("check_leaving",2,me);

			  return 0;

			}

		  enemy = offensive_target(me);


		  if( enemy && enemy->query_temp("yield") )

		  {

				  if(!objectp(weapon = me->query_temp("weapon"))

						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
						}
					else
					  message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);


					message_vision(HIY"\n$N��������ȫ��̲�ɱ���ֿ�֮�ˣ���λ"+RANK_D->query_respect(enemy)+HIY"���߰ɣ�\n"NOR, me);

					me->remove_all_enemy();

					me->delete_temp("pending/beidou");
					me->delete_temp("beidou_time");
					me->delete_temp("bd_pos");
					me->delete_temp("bd_power");
					room->delete_temp("ob1");
					room->delete_temp("ob2");
					room->delete_temp("ob3");

					call_out("check_leaving",2,me);
					return 0;
		  }


		  if ( me->query("neili") < 60 || me->query("jingli")<50 )
		  {
				  if(!objectp(weapon = me->query_temp("weapon"))
						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIY"\n$N������֧��ֻ���������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
						}
				  else
						message_vision(HIY"\n$N������֧��ֻ���������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);

					me->remove_all_enemy();
					me->delete_temp("pending/beidou");
					me->delete_temp("beidou_time");
					me->delete_temp("bd_pos");
					me->delete_temp("bd_power");
					call_out("check_leaving",2,me);
					 return 0;
		  }

		  if( !( room->query_temp("ob1",1) &&
				(objectp(ob1=present( room->query_temp("ob1",1),where) ) ) && ob1->query_temp("beidou_time") &&
				(objectp(ob2=present( room->query_temp("ob2",1),where) ) ) && ob2->query_temp("beidou_time") &&
				(objectp(ob3=present( room->query_temp("ob3",1),where) ) ) && ob3->query_temp("beidou_time") )
			 )
			 {
				  if(!objectp(weapon = me->query_temp("weapon"))
						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
						}
					else
					  message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);

					me->remove_all_enemy();
					me->delete_temp("pending/beidou");
					me->delete_temp("beidou_time");
					me->delete_temp("bd_pos");
					me->delete_temp("bd_power");
					room->delete_temp("ob1");
					room->delete_temp("ob2");
					room->delete_temp("ob3");

					call_out("check_leaving",2,me);
					return 0;
			 }


		  beidou_time = beidou_time-1;
		  me->set_temp("beidou_time", beidou_time);

		  bonus = random( ( me->query("int")+me->query("con")+25 ) / 30 ) + (me->query("int")+me->query("con")+25 ) / 30;
		  if( bonus > 3 ) bonus = 3;


		  if(enemy) bonus = bonus * 2 * ( enemy->query("combat_exp") - me->query("combat_exp") ) / me->query("combat_exp");
		  else bonus = 0;

		  if( bonus <0 ) bonus = 0;
		  if( bonus > 8 ) bonus = 8;

		  if( (int)me->query("potential") < (int)me->query("max_potential") )
					 me->add( "potential", bonus/2 );

		  me->add( "combat_exp", bonus*2/3 );
		  me->improve_skill( "beidou-zhenfa", random(bonus*2/3) );

		  enemy = offensive_target(me);

		  power = me->query_temp("bd_power",1)*4;


		  if( random(6)==1 )
		  {
			  tell_room(environment(me), HIR"\n" + zhen[(int)random(4)] +"\n"NOR, this_object());

			  if( objectp(enemy) && objectp( present( enemy->query("id"),environment(me) )) )
				  enemy->start_busy( random(2) );
		  }

		  if( objectp(enemy) && objectp( present( enemy->query("id"),environment(me) )) )
		  {
			  me->set_temp("apply/parry",me->query_temp("apply/parry",1)+power);
			  me->set_temp("apply/armor",me->query_temp("apply/armor",1)+power);
			  if( random(2)==1 )
			  {
				  if(random(2)==0)
					  message_vision("\n" + position[mypos] + "λ�ϵ�$N������������񹦣���Ȼ����������������ǰһ��, ����", me);
				  else message_vision("\n" + position[mypos] + "λ�ϵ�$Nͦ������������������ƮƮ��������硣ֻ��", me);

				  me->set_temp("apply/damage",me->query_temp("apply/damage",1)+power/2);
				  me->set_temp("apply/attack",me->query_temp("apply/attack",1)+power/2);
				  COMBAT_D->do_attack(me, enemy, me->query_temp("weapon"));
				  me->set_temp("apply/damage",me->query_temp("apply/damage",1)-power/2);
				  me->set_temp("apply/attack",me->query_temp("apply/attack",1)-power/2);
				  me->receive_damage("jingli", 15+random(15), "��ת�������������");
				  me->add("neili", -20-random(20));
			  }
			  me->set_temp("apply/parry",me->query_temp("apply/parry",1)-power);
			  me->set_temp("apply/armor",me->query_temp("apply/armor",1)-power);
			  return 1;
		  }
		  else
		  {
				if ( random(3)==1 )
				{
					if( ( weapon = me->query_temp("weapon") )
						 && (string)weapon->query("skill_type") == "sword" )
					{
						message_vision("\n" + position[mypos] + "λ�ϵ�$N"+ sword[random(10)]+"\n", me);
					}

					me->receive_damage("jingli", 15+random(10), "��ϰ�������������");
					me->add("neili", -20-random(15) );
				}
		  }


	 me->delete_temp("pending/beidou");
	 me->delete_temp("beidou_time");
	 me->delete_temp("bd_pos", mypos);
	  if(!objectp(weapon = me->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "sword" )
			{
				message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
			}
		else
			message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);


	 call_out("check_leaving",5,me);
	 return 0;
}

void restart (object me)
{
	start_beidouzhen(me, me->query_temp("bd_pos"), me->query_temp("beidou_time",1) );
}

int halt_beidou(object me)
{
	  object weapon;
	  int beidou_time = (int)me->query_temp("beidou_time",1);
	  if (beidou_time > 0)
	  {
			if( !living(me) ) return 1;

			if(random(2)==1)
			{
				message_vision(HIG"\n$N������һ�������ˤ��������\n"NOR, me);
			}
			else message_vision(HIG"\n$N����Ļ��˼��Σ�������վ���˲��ӡ�\n"NOR, me);
			call_out("restart",4,me);
			return 1;
	  }

	  if(!objectp(weapon = me->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "sword" )
		{
			message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
		}
		else
			message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);

	  me->delete_temp("pending/beidou");
	  me->delete_temp("beidou_time");
	  me->delete_temp("bd_pos");
	  me->delete_temp("bd_power");
	  return 1;
}

int stop_beidou()
{
	  object weapon,me=this_player();
	  if(!me->query_temp("pending/beidou"))
					 return notify_fail("ͣʲô���㲻�����С�������󡹡�\n");
	  if(!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
	  {
		message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
		}
	 else
		message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);

	  me->remove_all_enemy();
	  me->delete_temp("pending/beidou");
	  me->delete_temp("beidou_time");
	  me->delete_temp("bd_pos");
	  me->delete_temp("bd_power");
	  return 1;
}



int help(object me)
{
		  write(@HELP
ָ���ʽ : beidou3 <enemy> <����1> <����2> <����3>

���ָ���������ͬ��һ������������

��ο����ָ�� beidou
HELP
		  );
		  return 1;
}


