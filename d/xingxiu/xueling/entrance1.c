// Code of ShenZhou
// entrance1 for fighting ground

inherit ROOM;
#include <ansi.h>
int valid_leave();
int do_cun();

#define CANGKU "/d/xingxiu/xueling/cangku"
#include "battlefield.h"

void create()
{
  set("short", HIG"ȺӢ��"NOR);
  set("long", @LONG
���������Խ�ɽׯ��Ӣ������Ϣ��̸�ĵط����˼����˻�δ����
����Ⱥ�۶��Ѿ������ɴ�����������������Խ�ͤ����˵�в������
���������ű��м���С�˰��������������Я������Ʒ��
LONG
  );
  set("no_fight", 1);
  set("invalid_startroom", 1);
  set("exits", ([
		 "enter" : __DIR__"entrance2",
		 ]));
  setup();
}

void init()
{
  disableCmds();
}


int valid_leave(object who, string dir) {
  object room = this_object();
  object player = this_player();
  object *inv;
  object *old_basket, *basket;
  object cangku;
  int i;

  if (player->query_all_condition())
    return notify_fail("�ſڵ�С�˿�����һ�۵����������в��ʣ����Ǹ��������ɡ�\n");

  inv = all_inventory(player);
  basket = allocate(sizeof(inv));

  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
    cangku = load_object(CANGKU);
    if (!objectp(cangku)) {
      message_vision("$N����� wiz: cangku not found\n", player);
      return 0;
    }
  }

  for (i=0; i<sizeof(inv); i++) {
    if (! inv[i]->query_autoload()) { // leave yudi etc.
      basket[i] = inv[i];
      inv[i]->move(cangku);
      message_vision("$N��һ"+
	inv[i]->query("unit")+
	inv[i]->query("name")+"����С�ˡ�\n", player);
    }else{
      basket[i] = 0;
    }
  }
  old_basket=cangku->query("basket/"+player->query("id"));
  if (arrayp(old_basket)) basket = basket + old_basket;
  cangku->set("basket/"+player->query("id"), basket);
  player->set_temp("xueling/playing", 1);
  return ::valid_leave(who, dir);
}
