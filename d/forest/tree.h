// Code of ShenZhou
// Jay 7/11/96

inherit ROOM;

int do_climb(string);

void init()
{
        add_action("do_climb","climb");
        add_action("do_climb","pa");
}

int do_climb(string arg)
{
    object me, here, ob;
    object *all;
    string destination;
    me = this_player();
    here = this_object();
    all = all_inventory(here);

    if (me->is_busy())
        return notify_fail("��������æ���أ���\n");
    
    switch (arg) {
    case "up":
    case "shang":
        if ((string) destination = here->query("climbup")) {
          write("��������ȥ��\n");
          message("vision", me->name() + "��������ȥ�ˡ�\n",
                  environment(me),({me}));
          me->move(destination);

          if (random(5) == sizeof(all)) {
                ob = new("/d/city/npc/maque");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/xingxiu/npc/snake");
                ob->move(here);
          }

          message("vision", me->name() + "����������������\n",
                  environment(me), ({me}));
        }  
        else write("���ﲻ����������\n");
        break;
    case "down":
    case "xia":
        if ((string) destination = here->query("climbdown")) {
          write("��������ȥ��\n");
          message("vision", me->name() + "��������ȥ�ˡ�\n",
                  environment(me),({me}));
          me->move(destination);
          if (random(5) == sizeof(all)) {
                ob = new("/d/city/npc/maque");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/xingxiu/npc/snake");
                ob->move(here);
          }

          message("vision", me->name() + "����������������\n",
                  environment(me), ({me}));
        }
        else write("���ﲻ����������\n");
        break;
    case "left":
    case "zuo":
        if ((string) destination = here->query("climbleft")) {
          write("���������ȥ��\n");
          message("vision", me->name() + "������֦��������ȥ�ˡ�\n",
                  environment(me),({me}));
          me->move(destination);
          if (random(5) == sizeof(all)) {
                ob = new("/d/city/npc/maque");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/wudang/npc/monkey");
                ob->move(here);
          }

          message("vision", me->name() + "���ұߵ��˹�����\n",
                  environment(me), ({me}));
        }
        else write("���ﲻ����������\n");
        break;
    case "right":
    case "you":
        if ((string) destination = here->query("climbright")) {
        write("�����ұ���ȥ��\n");
          message("vision", me->name() + "������֦��������ȥ�ˡ�\n",
                  environment(me),({me}));
          me->move(destination);
          if (random(5) == sizeof(all)) {
                ob = new("/d/wudang/npc/little_monkey");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/xingxiu/npc/snake");
                ob->move(here);
          }

          message("vision", me->name() + "����ߵ��˹�����\n",
                  environment(me), ({me}));
        }
        else write("���ﲻ����������\n");
        break;
    default:
        return 0;
    }
    return 1;
}
