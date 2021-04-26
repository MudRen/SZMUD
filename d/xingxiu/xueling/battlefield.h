// Code of ShenZhou

#ifndef _BATTLE_FIELD_H_
#define _BATTLE_FIELD_H_

void createRoom() {
  set("no_death", 1);
  set("invalid_startroom", 1);
}

void disableCmds() {
  add_action("do_disable", "quit");
  add_action("do_disable", "lian");
  add_action("do_disable", "dazuo");
  add_action("do_disable", "tuna");
  add_action("do_disable", "exercise");
}

void initRoom() {
  add_action("do_finish", "finish");
  add_action("do_kickout", "kickout");
  disableCmds();
}

int do_disable()
{
  tell_object(this_player(), "�㲻��������������\n");
  return 1;
}

// clean up all the flags on a player, set back conditions etc.
void finish(object target) 
{
  if (!living(target)) target->revive();
  target->move("/d/xingxiu/xueling/exit1");
}

int do_kickout(string arg) 
{
  object player=this_player();
  object room=this_object();
  object target;

  if (! wizardp(player))  // only wiz can kickout someone
    return 0;

  if (! arg || arg=="")
    return notify_fail("��Ҫ��˭���ߣ�\n");

  target = present(arg, room);
  if (!target) 
    return notify_fail("����û������ˣ�\n");

  if (! userp(target))
    return notify_fail("��ֻ�ܸ�����ҡ�\n");

  message_vision("$N���˼����˸��ߡ�\n", target);
  finish(target);
  
  return 1;
}


int do_finish(string arg)
{
  object player=this_player();
  object room=this_object();
  object target;

  if (! arg || arg=="")
    return notify_fail("��Ҫ���˭��\n");

  target = present(arg, room);
  if (!target) 
    return notify_fail("����û������ˣ�\n");

  if (! userp(target))
    return notify_fail("�������Ǹ���ң�\n");

  if (!living(target) || target->query("qi")<0 || 
	target->query("jing")<0 || target->query("jingli") < 0) {
      message_vision("$N��ݺݵ�һ�Ű�$n�߳����䳡��\n", player, target);
  }else {
      if (target->query("qi") > 1 || target->query("jing") > 1 || 
          target->query("jingli") > 1) 
      return notify_fail("�˼һ�û���أ��ȴ�һ�ܰɣ�\n");

      message_vision("$N��ݺݵ�һ�Ű�$n��ʬ���߳����䳡��\n", player, target);
  }
  finish(target);
  
  return 1;
}

#endif
