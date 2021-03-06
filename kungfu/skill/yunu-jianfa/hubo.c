//code by Slow
#include <ansi.h>
inherit F_SSERVER;
		
string	*hubo_msg = ({
HIG"\n$N剑尖颤动，$n左腕、右腕、左腿、右腿各已中剑，大吼一声，倒地不起。\n"NOR,
HIG"\n$N秀眉微蹙，左手剑倏地递出，快如电闪，向$n刺了过去。\n"NOR,
HIG"\n$N将剑斜出，剑尖颤处，已刺中$n左腕。\n"NOR,
HIG"\n$N左一剑，右一剑，连刺四剑，$n身子摇晃，右腕中剑。\n"NOR,
HIG"\n$n见$N仗剑伫立，旁若无人，先沉不住气了，虎吼一声，向$N疾冲过去,$n一出手\n
攻击，身左便露出空隙，$N长剑抖动,只见$n左肩衣服上已刺破一个小孔，鲜血渗出。\n"NOR,
	});

string *dodge_msg = ({
		CYN"\n这顷刻之间，$N双剑已刺削点斩，一共出了四十余招，$n守得滴水不漏，\n
每一招均撞在兵刃之上在众人听来，只不过一下兵刃碰击的长声而已。\n"NOR,
		CYN"\n$N急攻不下，也佩服$n守得竟如此严密，微微一顿，轻飘飘的向后略退。\n"NOR,
		CYN"\n$N双剑微颤，似攻非攻，蓄势待发，却不出击，教$n不敢稍有弛缓。\n"NOR,
CYN"\n$N见$n越来越近，招数中却仍是无隙可乘,当下双剑连刺,连攻数十剑，尽数给挡了回来。\n"NOR,
	});

int perform(object me, object target)
{
	object weapon,weapon2;
 	object *inv;
       int skill;
       int count,i;
       int ap,dp;
	int hubo_skill,num;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("左右互博只能对战斗中的对手使用。\n");
       
/*
     if( me->query("newhubo") != 1 )
                   return notify_fail("你未收高人指点，无法施展左右互博！\n");
*/
       if( me->query_skill_mapped("force") != "yunu-xinjing" )
                   return notify_fail("你所用的并非玉女心经，无法施展左右互博！\n");
   
       if( me->query_skill("yunu-xinjing", 1) < 100 )
                   return notify_fail("你的玉女心经火候未到，无法施展左右互博！\n");
       
 	if( (hubo_skill = me->query_skill("zuoyou-hubo", 1)) < 100 )
                return notify_fail("你的左右互博还未精通！\n");
   
       if( me->query_skill("yunu-jianfa",1) < 135 )
                   return notify_fail("你的玉女剑法修为不足，怎么左右互博? \n");
       
        if( me->query_skill("quanzhen-jian",1) < 135 )
                 return notify_fail("你的全真剑法修为不足，怎么左右互博? \n");
/*
        if (me->query_temp("gm_suxin"))
             return notify_fail("你已经在使用素心决了\n");
*/
       
	if (me->query_temp("hubo") || me->query_temp("hebi"))
               return notify_fail("你正在互博呢！\n");
       
	inv = all_inventory(me); 
       
	for(i=0; i<sizeof(inv); i++)
	{ 
               if( inv[i]->query("equipped") || weapon == inv[i] ) continue; 
               if( inv[i]->query("skill_type") == "sword" )  
               { 
        	        weapon2 = inv[i]; 
              	  break; 
                }
 	} 
       
     
	 if( me->query("neili") < 500 )
                   return notify_fail("你的内力不够使用左右互博！\n");
       
	if( me->query("jingli") < 300 )
                 return notify_fail("你的精力不够使用左右互博！\n");
       
	if (me->query_temp("hubo") || me->query_temp("hebi"))
               return notify_fail("你正在互博呢！\n");

	if( !objectp(weapon2) ) 
                    return notify_fail("必须持有双剑才能和璧左右互搏！\n"); 

       message_vision(HIR "$N突然间左手抽出另一把剑，双手使出截然不同的剑法，正是左右互搏绝技。
		\n"+HIC"只见$N双剑一交，左右手玉女剑法与全真剑法配合得天衣无缝，攻守之势猛然大增！\n\n" NOR, me); 
         me->add("neili",-(200+random(100)));
       
        num = hubo_skill / 20;
	me->set_temp("hubo",num);
        call_out("hubo_checking", 0, me);
           return 1;
}

void hubo_checking(object me)
{
         object  target;
	int	ap,dp,damage,num;
	string msg1,msg2;
	object weapon = me->query_temp("weapon");
	num = me->query_temp("hubo");
        if( !target ) target = offensive_target(me);
	
         if (!me->query_temp("hubo"))
          {
           message_vision(HIY "\n$N正在忙着，只好收回左右互搏绝技！\n\n" NOR, me); 
           me->delete_temp("hubo");
           return;
          }
	if (num<1)
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$N吸了一口气，左手潇洒地地将剑插回剑鞘，收回左右互搏绝技！\n\n" NOR, me);
		return;

	}
	if( !me ) return;

        if( !me->is_fighting() || !living(me) || me->is_ghost() ||  !living(me) )
	{
                message_vision(HIY "\n$N吸了一口气，左手潇洒地地将剑插回剑鞘，收回左右互搏绝技！\n\n" NOR, me);
              me->delete_temp("hubo");
		return;
	}
	else if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$N手中无剑，不能继续互博了！\n"NOR, me);
		return;
	}
        if( !target || !target->is_character() || !me->is_fighting(target) )
        {
                 me->delete_temp("hubo");
                 message_vision(HIY "\n$N吸了一口气，左手潇洒地地将剑插回剑鞘，收回左右互搏绝技！\n\n" NOR, me);
                 return;
        }
/*
	else if( me->query_skill_mapped("sword") != "yunu-jianfa"
	|| me->query_skill_mapped("sword") != "quanzhen-jian" )
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$N突然改用其他剑法，不能继续互博了！\n"NOR, me);
		return;

	}
*/
	else if( me->query("neili") <= 500 )
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$N内力不足，不能继续互博了！\n"NOR, me);
		return;
	}   
	msg1 = hubo_msg[random(sizeof(hubo_msg))];
	msg2 = dodge_msg[random(sizeof(dodge_msg))];

	me->set_temp("hubo",num-1);     
        damage = me->query_skill("yunu-jianfa",1)+me->query_skill("quanzhen-jian",1)+me->query_skill("zuoyou-hubo",1);
	damage = damage * (1+ num /10);   
        if ((me->query("combat_exp")/2+random(me->query("combat_exp")))
        >target->query("combat_exp")/2+random(target->query("combat_exp")/2))
	{	
		target->start_busy(2);
		message_vision(msg1,me,target);
		target->receive_damage("qi", damage,  me); 
		target->receive_wound("qi", random(damage/3)+damage/3, me); 
		COMBAT_D->report_status(target); 
	 }
	else
	{
		message_vision(msg2,me,target);
	}
        call_out("hubo_checking", 1, me, target);
}       
