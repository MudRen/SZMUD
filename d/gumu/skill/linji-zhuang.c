//Cracked by Kafei
// linji-zhuang.c �ټ�ʮ��ׯ (emei force)
// xuy@xkx

#include <ansi.h>

inherit FORCE;
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

string *skill_name = ({
  "����ׯ",
  "����ׯ",
  "֮��ׯ",
  "����ׯ",
  "����ׯ",
  "����ׯ",
  "����ׯ",
  "Ʈ��ׯ",
  "����ׯ",
  "С��ׯ",
  "����ׯ",
  "ڤ��ׯ",
  "�ټ�ʮ��ׯ",
});

string *combo_name = ({
  "���",
  "֮��",
  "����",
  "����",
  "��С",
  "��ڤ",
});

int valid_enable(string usage)
{
  return usage == "force";
}

int valid_learn(object me)
{
  mapping skl; 
  string *sname;
  int v, k=0;

  int i, nb, np, nf, nl;
  nb = (int)me->query_skill("mahayana", 1);
  np = (int)me->query_skill("persuading", 1);
  nf = (int)me->query_skill("force", 1);
  nl = (int)me->query_skill("linji-zhuang", 1);

  skl=this_player()->query_skills();
  sname=sort_array( keys(skl), (: strcmp :) );

  if(me->query_skill("linji-zhuang", 1) > 99){

    for(v=0; v<sizeof(skl); v++) {
      if (SKILL_D(sname[v])->check() == "force")
	k++;  
    }

    if ( k >=2 )
      return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n");
  }


  if ( nl >= 20 && nb < 150 && nb <= nl )
    return notify_fail("��Ĵ�����ͷ���Ϊ�������޷�������������ټ�ʮ��ׯ��\n");
  if ( (nl >= 60 && np < 150 && np <= nl ) || np <= nl/2 )
    return notify_fail("��Ķ���������ҵ���ò������޷�������������ټ�ʮ��ׯ��\n");

  if ( nf < 10 || nf/2 < nl/3 )
    return notify_fail("��Ļ����ڹ���򻹲������޷������ټ�ʮ��ׯ��\n");

  return 1;
}


int practice_skill(object me)
{
  return notify_fail("�ټ�ʮ��ׯֻ����ѧ(learn)�������������ȡ�\n");
}

string query_skill_name(int level)
{
  if (level < 180) return skill_name[level/15];
  else return skill_name[12];
}
string exert_function_file(string func)
{
  return __DIR__"linji-zhuang/" + func;
}

void skill_improved(object me)
{
  int level = me->query_skill("linji-zhuang",1);
  int o_lvl = me->query("linji_lvl");
  int i;

  if ( level > 180 ) return;

  if ( level/15*15 == level ) {
    tell_object(me, HIG "��ԡ�" + skill_name[level/15-1] + "���ѻ�Ȼ��ͨ��\n"NOR);
    if (o_lvl < level) {
      tell_object(me, HIG"��ʱ��Ի����ڹ�������Ҳ�����ߡ�\n"NOR);
      for (i=0; i< level; i++)		
	me->improve_skill("force", level);
    }
  }

  if ( level/30*30 == level ) 
    if (o_lvl < level) {
      tell_object(me, HIY"��ʱ��" + combo_name[level/30-1] +
		  "��ׯ�ڻ��ͨ��һ����͵���������ȫ��������Ϊ��������һ�㡣\n"NOR);
      me->add("max_neili", level);
    }
	

  if ( o_lvl < level ) me->set("linji_lvl", level);
		
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
  int lvl = victim->query_skill("linji-zhuang", 1);

  // Buddha force (similar to shaolin):
  // 
  // If we have enough neili, no matter how strong our enemy is, we have
  // chance to rebounce.
  // 
  if (victim->query("neili")>lvl*10 && random(lvl*lvl + 32400) > 32400) {
    return - lvl; 
  }

  // If we failed to rebonuce, we have the chance to reduce the damage

  // need certain amount of neili to reduce damage
  if (victim->query("neili") < lvl*3) return damage;

  // note that this only matters with force part of the damage, the other factors of
  // damage, such as weapon, skill will still be applied. So even if we return 0 here,
  // the damage could be a few hundreds still.  Don't panic!
  if (lvl > 200) return 0;

  return damage * (40000 - lvl*lvl)/100000;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"	: HIY"��һ��������ʱ���������һ��ů������������\n"NOR,
	]);
}
