  // Ư���ı�ʯ ����  ��/obj/gem.c
  // by naihe �κ�  2002-05-15
  /* 
  ��ȫ�Լ�д�Ĵ��룬һ�㶼û�г���������  ֪ʶ���Ѿ������������ˣ��ߣ��Ҳ�����һ���ϣ�
  ���˲���20���ֶ���ʵ�ָ����ط��������������

  ��ʵ��������ѧ�����֣�����д���򣬴�������ؼ���һ�������ּ�����Ϊ�����ֱ������ģ�
  ���ֱ�����Ϊ��ѧ����ġ���ͬ��������Ҳ��Ϊ�����ǵĳ��������û�кõ����մ��⣬��
  �ߵļ��ɣ������ٶ�����֪���ٶ���ڲ�����ʽ����д�����Ķ�����Ҳ���������Ч�ʵģ�
  ��������������õģ�����

  �պ��дЩ��Щ�仯��Ķ����������������յĶ����ɡ�

  ͻȻ��������������Ļ���Ҳ���������𣡣���ȥ�������Ĵ�����У�����
  ����һ��������ʲô���Ķ�û�ˣ����˼ҵĴ���д�ö��࣡��  ��ϧ��ô�õĴ��뼼����̣�ˣ�
  д����������Ϸ��ô�ã��ߺ�
  */

#include <ansi.h>
  inherit ITEM;

  string clname,smash,
  smash="not";

  int color=(random(5));


  void create()
  {
          if(color==0)
          {
                  set_name(HIG"�̱�ʯ"NOR, ({"gem","baoshi","green gem"}));
                  clname="��";
          }

          if(color==1)
          {
                  set_name(HIR"�챦ʯ"NOR, ({"gem","baoshi","red gem"}));
                  clname="��";
          }

          if(color==2)
          {
                  set_name(HIB"����ʯ"NOR, ({"gem","baoshi","blue gem"}));
                  clname="��";
          }

          if(color==3)
          {
                  set_name(HIM"�ϱ�ʯ"NOR, ({"gem","baoshi","violet gem"}));
                  clname="��";
          }

          if(color==4)
          {
                  set_name(HIC"������ʯ"NOR, ({"gem","baoshi","sapphire gem"}));
                  clname="����";
          }

  // ����Ĵ�����ʵ���ǲ���д�������ģ���ϧ�����˺ܶ���ϵķ�ʽ�������ɹ���
  // ��ֻ��д����ô������������������Ҳ�ã��ȶ���  yeah~~~~~~~~

          switch(random(10))
          {
                  case 0:set("long","һ��"+clname+"ɫ�ı�ʯ���������˵Ĺ�â��\n");
                  break;

                  case 1:set("long","��ű�ʯɫ����������"+clname+"����ȫ��"+clname+"�����˰������֡�\n");
                  break;

                  case 2:set("long","��ʯ�����ĵ�ɢ����"+clname+"ɫ�Ĺ�â��\n");
                  break;

                  case 3:set("long","���"+clname+"��ʯԲԲ���Ƹ�С��ģ����ɷ�ǿɰ���\n");
                  break;

                  case 4:set("long","����һ��"+clname+"ɫ��С��ʯ�������ƺ���Щ���������飨smashup����Ҳ���ܹ����ø������\n");
                  smash="can";
                  break;

                  case 5:set("long",clname+"��ʯ�����ƺ���Щ����������������飨smashup�������޷����塣\n");
                  smash="can";
                  break;

                  case 6:set("long","��ʯ��ɢ����"+clname+"ɫ�Ĺ�â��ӳ������������������������˼��\n");
                  break;

                  case 7:set("long","��ʯ�ﵭ����ɢ����"+clname+"ɫ�Ĺ�â��\n");
                  break;

                  case 8:set("long","����ϸ�ؿ��˿����ƺ�"+clname+"��ʯ������ż���СС���֣�for spark ��\n");
                  break;

                  case 9:set("long","����һ�Ű����޹�ı�ʯ����Լ�����ƺ���"+clname+"ɫ��\n");
                  break;
          }

          set_weight(30);
          set("unit", "��");
          set("value", 0);

          setup();
  }

  void init()
  {
          if(smash=="can") add_action("do_smashup","smashup");
  }

  void del_me()
  {
          message_vision(""MAG"ֻ��һ������ð��С������ʧ�����ˡ�"NOR"\n",this_player());
          destruct(this_object());
  }


  int do_smashup(string arg)
  {
          object me=this_player();
          if(random(2)==1)
          {
                  message_vision(HIW"$N�����ذ�"+clname+"��ʯ��������ȥ��\nֻ��"+clname+"��ʯһ�������˿���������ȴʲô��û�С�"NOR"\n",me);
                  destruct(this_object());
                  return 1;
          }
          message_vision(HIW"$N�����ذ�"+clname+"��ʯ��������ȥ��\nֻ��"+clname+"��ʯһ�������˿�����ԭ��������һƬС������"NOR"\n",me);
          set_name(MAG"С����"NOR, ({"things"}));
          set("long",""MAG"��ɽ�κα����Ҳ�"NOR"\n");
          set("unit","Ƭ");
          set_weight(10);
          smash="not";
          call_out("del_me",5+random(10));
          this_object()->move(environment(me));
          return 1;
  }


