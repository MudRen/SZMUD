// Code by Scatter
// Chinese By Chchong
// 戚然销魂掌
// xiaohun-zhang 2.2A

#include <ansi.h>

inherit F_SSERVER;

//Start from Here, Testing Perform Restriction
int perform(object me, object target)
{
  object ob;
  string msg;
  int damage;
  int finger, skill, jiali, my_rate, your_rate;

  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() ||  !me->is_fighting(target) )
	 return notify_fail("瀑布惊雷只能在战斗中用。\n");

  if( me->query_temp("yield") )
	 return notify_fail("你不出手，如何使得出瀑布惊雷？\n");

  if( (skill = (int)me->query_skill("yunu-xinjing", 1)) < 100 )
	 return notify_fail("你对玉女心经了解不够深入, 无法使出瀑布惊雷。\n");

  if( me->query_skill("strike") < 120 )
	 return notify_fail("你的戚然销魂掌不够熟练, 无法使出瀑布惊雷。\n");

  if( me->query_skill_mapped("force") != "yunu-xinjing" )
	 return notify_fail("你所用的并非玉女心经，无法使出瀑布惊雷！\n");

  if( me->query("neili") < 300 ) return notify_fail("你现在内力不足，无法使出瀑布惊雷。\n");


//Start From Here,  Acture Perform Display


/*
[14] about pfm jinglei                        臭虫(chchong)(Fri Aug 10)
----------------------------------------------------------------------
发招时的描述! "突然$N脸色大变,招式也越发凌厉,向$n劈出一掌,
隐约之间发出惊雷般的响声,掌风到处砂飞石动宛然如惊涛拍岸,气势磅礴让人只能招架不能躲闪!"
中招描述! "$n突然觉得$N招式突变,一掌过来胸口顿时呼吸不畅,慌乱之中架了一招,顿时感觉气血翻涌有说不出的难受!"
*/



//***** Perform Message *****
  msg = HIY "\n突然$N脸色大变,招式也越发凌厉,向$n劈出一掌。\n\n"NOR;
  msg += HIB"隐约之间发出惊雷般的响声,掌风到处砂飞石动宛然如惊涛拍岸,\n";
  msg += HIW"气势磅礴让人只能招架不能躲闪!\n";


//***** TESTING CONDITION *****
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			if(damage > 3000) damage = 3000;
			if(damage < 500) damage = 500;
			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

//		msg += HIR"猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;
		if ( damage < 1000) {
			msg += HIC"突然之间$n感觉一股巨大的掌风向自己袭来,急忙闪开,结果还是被拍中了右臂,后退了几步!\n"NOR;
		}else if ( damage < 1500) {
			msg += HIR"只见$N脸色大变发出凌厉的一掌,掌中夹杂着哄哄闷雷之声,眨眼之间击中了$n的小腹,$n立感不支被震退数步勉强站住!\n"NOR;
		}else if ( damage < 2000) {
			msg += YEL"$n正在诧异此招数怎么如此声势巨大,胸口已经被$N所发的重手拍中,只觉得气血翻腾,真气好象要涌出身体,;脸色由红变紫,由紫变红数次总算接住此招!\n"NOR;
		}else if ( damage < 2500) {
			msg += RED"$n只觉得$N右掌和雷声一起拍到$n胸口,顿时$n被腾云驾雾般震飞,五脏六腑好象换了位置,一口鲜血狂喷而出,再也经不起真气震荡!\n"NOR;
		}else if ( damage < 3000) {
			msg += RED"$N身影晃动,闪电般发出惊雷一掌,$n还未明白怎么回事胸口肋骨已被震断,鲜血从胸前渗了出来,可怕之极难以想象!\n"NOR;
		}else {
			msg += RED"猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;
		}
		msg += NOR;
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 2;
			if(damage > 2000) damage = 2000;
			if(damage < 350) damage = 350;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIY"$N此掌一出$n立刻凝运周身真气,片刻之间护住心脉,硬生生的接了一掌,不过$n显然吃了不少的亏!\n\n"NOR;
		if ( damage < 400) {
			msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
		}else if ( damage < 600) {
			msg += HIR"突然之间$n感觉一股巨大的掌风向自己袭来,急忙闪开,结果还是被拍中了右臂,后退了几步!\n"NOR;
		}else if ( damage < 1000) {
			msg += RED"$n只觉得$N右掌和雷声一起拍到$n胸口,顿时$n被腾云驾雾般震飞,五脏六腑好象换了位置,一口鲜血狂喷而出,再也经不起真气震荡!\n"NOR;
		}
		else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
	  random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 3;
			if(damage > 1000) damage = 1000;
			if(damage < 250) damage = 250;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIM"$N掌势一发$n便知自己已非敌手，无望之际已被掌力拍到，一口热血被震了出来，\n胸口肋骨寸断,身子瘫软在当地！\n\n"+NOR;
		if ( damage < 400) {
			msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
		}else if ( damage < 600) {
			msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
		}else if ( damage < 1000) {
			msg += RED"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。\n"NOR;
		}
		else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else {
	 msg += HIC"$n甚是狼狈的避开$N所发瀑布惊雷,不禁被所发招式吓出一身的冷汗,\n\n"NOR;
	 msg += HIW"面如死灰,僵在当地,脸上被掌风刮到之处也泛起了红印!\n" NOR;
	 me->add("neili", -300 );
	 me->add("jingli", -me->query("jiajin") );
	 me->start_busy(2 + random(2));
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
