// Code of ShenZhou
// entrance1 for fighting ground

inherit ROOM;
#include <ansi.h>

#define CANGKU "/d/xingxiu/xueling/cangku"
#include "battlefield.h"

void create()
{
  set("short", HIG"��Ϣ��"NOR);
  set("long", @LONG
�����Ǳ�����ϵ�Ӣ������Ϣ�ĵط������ߵ�С��������
����ǰ��ŵĸ������£������ص��Ŵ�������졣�������ȥ
�����Խ�ɽׯ�Ĵ����ˣ�
LONG
  );

  set("no_fight", 1);
  set("invalid_startroom", 1);
  set("exits", ([
		 "out" : __DIR__"gate",
		 ]));
  setup();
}

void init()
{
  object player = this_player();
  object *inv, cangku, *basket;
  int i;

  add_action("do_ling", "ling");
  disableCmds();
  player->clear_condition();
  player->set("eff_qi", player->query("max_qi"));
  player->set("qi", player->query("max_qi"));
  player->set("eff_jing", player->query("max_jing"));
  player->set("jing", player->query("max_jing"));
  player->set("jingli", player->query("max_jingli"));
  player->set("neili", player->query("max_jingli")/10);
  if (objectp(player)) {
    player->remove_all_killer();
    inv = all_inventory(player);
    for (i=0; i<sizeof(inv); i++) {
      if (inv[i]->query_temp("xueling")) { // created by us
        message_vision("$N�Ѵ��Խ�ͤȡ��"+inv[i]->query("name")+"����С�ˡ�\n", 
	player);
	destruct(inv[i]);
      }
    }
  }
  
  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
    cangku = load_object(CANGKU);
    if (!objectp(cangku)) {
      message_vision("$N����� wiz: cangku not found\n", player);
      return 0;
    }
  }
  basket = cangku->query("basket/"+player->query("id"));

  if (basket) {
    for (i=0; i<sizeof(basket); i++) {
      if (objectp(basket[i])) {
	basket[i]->move(player);
        message_vision("$N��С�������û�һ"+
		basket[i]->query("unit")+ 
		basket[i]->query("name")+"��\n", player);
      }
    }
    cangku->delete("basket/"+player->query("id"));
  }
  player->delete_temp("xueling");
}
