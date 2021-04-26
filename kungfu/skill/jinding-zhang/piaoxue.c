// Code of ShenZhou
// Ʈѩ������
// chu@xkx   6/16/98

#include <ansi.h>

inherit F_SSERVER;

#define SKILL_DB "/clone/obj/skill_db"

/*
 * succ:        0/1 success or not
 * rate_adjust: adjust my perform succ rate according to usage frequency
 * damage:      how much damage to qi
 * wound:       how much damage to eff_qi
 * neili_damage: how much damage to neili
 *
 */ 
mapping check_usage(object me, object target, int jiali)
{
  object skill_db;
  int freq, rate;
  mapping ret, px_info;

  seteuid(getuid());
  skill_db  = find_object(SKILL_DB);
  if (! objectp(skill_db)) skill_db = new(SKILL_DB);
  if (! objectp(skill_db)) return 0;

  ret = ([ "succ":1 ]);

  px_info = skill_db->update_usage("piaoxue", me, target, 50);
  freq = px_info["history"];
  if (freq < 3600)  ret["succ"] = 0;	// disable if used twice within an hour


  rate = px_info["rate"]*2;
  ret["rate_adjust"] = me->query("combat_exp")*(rate-100)/200;

  // assume jiali 200:
  // rate = 25:  damage = 200 * 25  / 15 = 333    (~ 4 uses per day)
  // rate = 50:  damage = 200 * 50  / 15 = 667    (~ 2 use per day)
  // rate = 100: damage = 200 * 100 / 15 = 1333   (average: 1 day)
  // rate = 200: damage = 200 * 200 / 15 = 2667   (1 use per 2 days)
  // rate = 300: damage = 200 * 300 / 15 = 4000   (1 use per 4 days)
  // rate = 400: damage = 200 * 400 / 15 = 5333   (1 use per 8 days)
  
  ret["rate"]         = rate;
  ret["damage"]       = rate * jiali / 15; 
  ret["wound"]        = rate * jiali / 25;	
  ret["neili_damage"] = rate * jiali / 40;    

  if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
    tell_object(me, sprintf("new px_info��%O\n", px_info));
    tell_object(me, sprintf("rate=%d, return value: ��%O\n", rate, ret));
  }

  return ret;
}

/* 
 * The rate consists of two parts: exp and skills, the scale of the rate is 
 * around 2-4 times a player's exp.
 *
 * exp_rate = exp 
 * skill_bonus = unarmed * force * int
 *
 * note that exp = max_skill*max_skill*max_skill/10
 * for a normal player, int is about 1/8 - 1/3 max_skill, so the skill
 * bonus has 1.5-3 times as much the effect of exp_rate.
 * 
 * This perform is supposed to be very relavent to one's IQ, so let int
 * be of some usage here.
 * 
 */

int compute_rate(object me, int jiali)
{
  int ret = me->query("combat_exp");

  int jdz = (int)me->query_skill("jinding-zhang", 1);  // jdz level
  int ljz = (int)me->query_skill("linji-zhuang", 1);   // ljz lvl
  int force = (int)me->query_skill("force", 1);   // basic force lvl
  int strike = (int)me->query_skill("strike", 1);   // basic strike lvl
  int cuff = (int)me->query_skill("cuff", 1);   // basic cuff lvl
  int unarmed_lvl, force_lvl;

  if (cuff > strike) strike = cuff;

    
  if (jiali > 0) {  // attacker
    unarmed_lvl = (jdz+strike)/2;
    force_lvl = (ljz+force)/2;
  }else{	
    // defender: if you know ljz and/or jdz, rate higher
    // but if you don't, then you rate 1/4 lower
    unarmed_lvl = strike/2+jdz;
    force_lvl = force/2+ljz;
  }
  return ret + unarmed_lvl * force_lvl * me->query_int();
}

int perform(object me, object target)
{
  object ob, db;
  string msg; 
  mapping usage_info, info;
  int finger, skill, jiali, my_rate, your_rate, rate, history, req;

  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() ||  !me->is_fighting(target) )
    return notify_fail("Ʈѩ������ֻ�������Ի�ս���еĶ��֡�\n");

  if( me->query_temp("yield") )
    return notify_fail("�㲻���֣����ʹ�ó�Ʈѩ�����ƣ�\n");

  if(objectp(ob= me->query_temp("piaoxue/target")) &&  ob->is_fighting(me) ) 
    return notify_fail("���Ѿ����Ի�����ˡ�\n");


  db = find_object("/clone/obj/skill_db");
  if (!objectp(db)) db = new("/clone/obj/skill_db");
  if (!objectp(db)) return notify_fail("Failed to load skill_db.  please report.");
  
  info=db->update_usage("piaoxue", me, 0, 0);
  // temporarily set the history
  if (time()-info["last_use"] > info["history"]) {
    history = info["history"];
    info["history"] = time() - info["last_use"];
  }
  rate = db->compute_rate(info);
  info["history"] = history;

  // requirement increases as the usage become more often
  if (rate >= 100) req = 200;
  else req = 150 + 5000 / (1 + rate);

  if( (finger = (int)me->query_skill("tiangang-zhi", 1)) < req )
    return notify_fail("������ָѨ��������죬�����ڻ��ͨ��ü�Ʒ���Ҫ��\n");

  if( (skill = (int)me->query_skill("jinding-zhang", 1)) < req )
    return notify_fail("��Ľ����Ʋ�����죬����ʹƮѩ�����ơ�\n");

  if (skill > finger) skill = finger; // use min(tgz, jdz)

  if( (int)me->query_skill("linji-zhuang", 1) < req )
    return notify_fail("����ټ�׮����Ϊ����������ʹ��Ʈѩ�����ơ�\n");

  if( me->query_skill_mapped("force") != "linji-zhuang" )
    return notify_fail("�����õĲ����ټ�׮��ʹ����Ʈѩ�����ƣ�\n");

  jiali=(int)me->query("jiali");
  if( jiali < 50 )
    return notify_fail("Ʈѩ�����������ڼҹ������ϲ�������ʹ��������\n");

  msg = HIY "\n$P���ƺ��ͣ�����һβ�����ޱȣ�Ѹ�����׵�С��һ�㣬����$n����ǰ��\n";
  msg += "$n��Ȼ��Ȼ�ķ��������ͶԷ�����������һ�������������ɾ޴���ھ�����δײ��\n";
  msg += "����δ��֮�ʣ�$P������ȴ��Ȼ��Ӱ���ٵ���ʧ�ˡ�\n\n";

  me->add("neili", -jiali);

  usage_info=check_usage(me, target, jiali);
  if (usage_info == 0) { // error!
    printf("Pleas report: skill_db not found.  bug..\n");
    return 1;
  }

  if (usage_info["succ"]) {
    my_rate = compute_rate(me, jiali);
    your_rate = compute_rate(target, 0);
    my_rate += usage_info["rate_adjust"];
    if (my_rate < 0) my_rate = 0;

    if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
      tell_object(me, sprintf("rates: my=%d, target=%d\n", my_rate, your_rate));
    }
    if (random(my_rate) >= your_rate/2) {
      msg += "$nһ����̧ͷ��$Pʱ���͵����ؿ���������������һ����\n";
      if (usage_info["damage"] < 50) {
	msg += "$n�ɻ�ؿ���$Pһ�۵����벻����ü���ڹ���˲�����ٴ�һ�����Կ���\n";
      }else if (usage_info["damage"] < 200) {
	msg += "$n����һ�Σ����㲻����������Ҫˤ����\n";
      }else if (usage_info["damage"] < 400) {
	msg += "$n���㲻����������ˤ����������۵�һ�������һ����Ѫ��\n";
      }else if (usage_info["damage"] < 800) {
	msg += "$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ��\n";
      }else if (usage_info["damage"] < 1600) {
	msg += "$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n";
      }else {
	msg += "ֻ��һ�����죬$n������Ѫ���磬ȫ��������ѣ��ۼ��ǻ���ˣ�\n";
      }

      msg += NOR;
      target->receive_damage("qi", usage_info["damage"], me);
      target->receive_wound("qi", usage_info["wound"], me);
      target->add("neili", -usage_info["neili_damage"]);
      me->set_temp("piaoxue/target", target);
      me->set_temp("piaoxue/usage_info", usage_info);
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 
			  skill/8);
      log_file("skill_usage", sprintf("%s %s(%s) piaoxue on %s(%s): rate=%d, jiali=%d, damage=%d\n",
	ctime(time()), me->name(1), geteuid(me), target->name(1), geteuid(target), usage_info["rate"], 
	jiali, usage_info["damage"]));
    }else{
      msg += "$n�����������ؿڣ��������$P��һ�ƣ�Ц����Ʈѩ�����ƺô����ͷ����ʹ��Ҳ������ˡ�\n" NOR;
      me->start_busy(random(3));
      log_file("skill_usage", sprintf("%s %s(%s) performed piaoxue on %s(%s): rate=%d missed\n",
	ctime(time()), me->name(1), geteuid(me), target->name(1), geteuid(target), usage_info["rate"]));
    }
  } else {
    msg += "$n��Ц�����������֮��˭�˲�֪��Ʈѩ�����ƣ�Ҳ����˼�����ֳ�\n";
    msg += "$n���²������˵�վ��һ��׮���������ӣ���$P�ľ�������жȥ��\n";
    msg += "$N���һ������࣬���ĵĿ��Ŵ󿪣��Ǳ����м��ţ�\n" NOR;
    me->start_busy(3 + random(4));
      log_file("skill_usage", sprintf("%s %s(%s) performed piaoxue on %s(%s): total failure\n",
	ctime(time()), me->name(1), geteuid(me), target->name(1), geteuid(target)));
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}

void remove_effect(object me)
{
  object target;

  if( me->query_temp("piaoxue") ) {
    target = me->query_temp("piaoxue/target");
    me->delete_temp("piaoxue");
    if( me->is_fighting() )
      message_vision(HIY "\n$n��������Ӧ��$P��Ʈѩ�����ơ�\n" NOR, me, target);
  }
}

