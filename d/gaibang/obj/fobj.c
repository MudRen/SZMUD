// Code of ShenZhou
#include <ansi.h>
#include <room.h>

inherit ITEM;

void create()
{
  set_name ("����", ({ "Fake_Image" }));
  set("env/invisibility", 10);
  setup();
}

void init()
{
  add_action("do_look","look");
}

int do_look(string arg) 
{
  object me;
  int i, ran, j, k;
  object *inv, env;
  mapping exits;
  string str, *dirs;

  me = this_player();

  if(arg) return 0;
  
  // let all ppl see
//  if( me->query("id") != query("target")) return 0; 

  env = environment(me);
  if( !env ) {
    write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
    return 1;
  }
  str = sprintf( "%s - %s\n    %s%s",
    env->query("short"),
    wizardp(me)? file_name(env): "",
    env->query("long"),
    env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

  if( mapp(exits = env->query("exits")) ) {
    dirs = keys(exits);
    for(i=0; i<sizeof(dirs); i++)
      if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
        dirs[i] = 0;
    dirs -= ({ 0 });
    if( sizeof(dirs)==0 )
      str += "    ����û���κ����Եĳ�·��\n";
    else if( sizeof(dirs)==1 )
      str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
    else
      str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
    implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
  }

  inv = all_inventory(env);
  for(i=0; i<sizeof(inv); i++) {
//    if( inv[i]==me && inv[i] != query("attacker")) continue;
    if( inv[i]==me ) continue;
    if( !me->visible(inv[i]) ) continue;
    if( objectp(inv[i]->query("rider")) ) continue;
    
    for(j = 0; j < query("attacker")[2]; j++) {
      if(inv[i] == query("attacker")[0][j]) {
        ran = random(4)+1;
        for(k = 0; k < ran; k++)
          str += "  " + inv[i]->short() + "\n";
        break;
      }
    }
    
    if( objectp(inv[i]->query("rided")) ) {
      str += "  " + inv[i]->short() + "����" + (inv[i]->query("rided"))->name() + "��";
      if( stringp(inv[i]->query_temp("exit_blocked")))
        str += "������"+inv[i]->query_temp("exit_blocked")+ "ȥ��·";
        str += "\n";
    }
    else {
      if (stringp(inv[i]->query_temp("exit_blocked")))
         str += "  " + inv[i]->short() + "������" + inv[i]->query_temp("exit_blocked")
               +"ȥ��·\n";
      else if( inv[i]->query_temp("riding") ) {
        str += "  " + inv[i]->short() + "�����ڳ���\n";
      }
      else
        str += "  " + inv[i]->short() + "\n";
        inv[i]->delete("rided");
    }
  }

  write(str);

  return 1;
}
