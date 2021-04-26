// Code of ShenZhou
// douzhuan.c ��ת����

#include <ansi.h>

inherit F_SSERVER;

#define DOU_ZHUAN "douzhuan"
#define DOU_FAKE_NAME "douzhuan/pretend_skill"
#define DOU_FAKE_TYPE "douzhuan/type"

#define UNARM_SKILL 5
#define SHORT_WEAPON_SKILL 3
#define LONG_WEAPON_SKILL 6

string *unarm_skill = ({ "strike", "cuff", "finger", "hand", "claw" });
string *short_weapon_skill = ({ "sword", "blade", "hook" });
string *long_weapon_skill = ({ "stick", "staff", "club", "whip", "hammer", "pike" });

private void remove_effect(object me, object target);

void create()
{
  seteuid(getuid());
}

int perform(object me, object target)
{
  string msg, str;
  object weapon, weapon1;
  string skill, fake_type;
  int ski_num;
  mapping tar_skills;
  
  if(me->query_temp(DOU_ZHUAN)) return notify_fail("���Ѿ���ʹ�ö�ת�����ˡ�\n");
  
  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character()
      || !me->is_fighting(target) )
    return notify_fail("��ת����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

  weapon = me->query_temp("weapon");
  weapon1 = target->query_temp("weapon");
  
  if( !weapon1 ) {
    if(weapon) {
      weapon->unequip();
      if( !stringp(str = weapon->query("unwield_msg")) )
        str = "$N�������е�$n��\n";
      message_vision(str, me, weapon);
    }
    
    ski_num = sizeof(unarm_skill);
    tar_skills = target->query_skill_prepare();
    for(int i = 0; i < ski_num; i++) {
      if(tar_skills[unarm_skill[i]]) {
        skill = tar_skills[unarm_skill[i]];
        me->set_temp(DOU_FAKE_NAME, skill);
        me->set_temp(DOU_FAKE_TYPE, "strike");
        break;
      }
    }
  }
  
  else {
    fake_type = weapon1->query("skill_type");
    skill = target->query_skill_mapped(fake_type);
    
    if(!me->query("env/wiz_test")) return notify_fail("�㲻�����ô���ʽ֮�ˡ�\n");
    if(!weapon || weapon->query("skill_type") != fake_type)
      return notify_fail("��û��������������\n");

    me->set_temp(DOU_FAKE_NAME, skill);
    me->set_temp(DOU_FAKE_TYPE, fake_type); 
    
/*    if(weapon = present("mweapon", me) ) {
      weapon->be_weapon(fake_type);
      me->set_temp(DOU_FAKE_NAME, skill);
      me->set_temp(DOU_FAKE_TYPE, fake_type);
    }
    
    else return notify_fail("��ʱ������ô�á�\n");*/
  }
  
    
  message_vision(HIY"$N���ö�ת���ƣ���$n������֮������������֮��ʹ��"+
    to_chinese(skill)+"\n"NOR, me, target);

  me->add("neili", -80);
  me->add("jingli", -20);

  call_out("remove_effect", 1, me, target);

  return 1;
}

private void remove_effect(object me, object target)
{
  if( !me->is_fighting() || !target || !target->is_character() 
     || !me->is_fighting(target) || !me->query_temp(DOU_ZHUAN) ) 
  {
    message_vision( HIY"��ת����ʹ�꣬$N�ѷ�����أ�blah blah blah��\n" NOR, me);
    me->delete_temp(DOU_ZHUAN);
    return;
  }
  
  call_out("remove_effect", 1, me, target);
  return;
}
