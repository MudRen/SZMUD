// Code of ShenZhou
// jiulao3.c ���϶�
// Shan: 96/06/22

int valid_leave(object me, string dir)
{
	me->receive_damage("jingli", 5, "�궴������");
        return ::valid_leave(me, dir);
}

int do_zuan(string arg)
{
      object me = this_player();

      message_vision(
      		"$N��ûͷ��Ӭһ���ڶ���Ϲ�꣬���һͷײ�ڶ����ϡ�\n", this_player());
      if (random(2)==1) {
         	write("��������κ����ģ��ƺ�ײɵ�ˡ�\n"); 
		// hehe, I am nice, no permanent literate decrease now:)
		// xixi, you are so nice.  I didn't realize that -1 means 1 level :)
             	me->add_temp("apply/intelligence", -1);
      }
      else {
         	me->receive_damage("jingli", 10+random(10), "�궴������");
      		write("��ת��תȥ������ת���˶��ڡ�\n");
		me->move(__DIR__"jiulao2");
      }
      return 1;
}

void fire_out(object me, object ob)
{
	object* inv = all_inventory(this_object());
	int i;
	for (i=0; i < sizeof(inv); i++) {
		if (inv[i]->is_character()) continue;
		destruct(inv[i]);
	}
	message("vision", "����һ��������еĻ��������ˣ�ʲôҲ�������ˣ�ֻ���������֨֨����\n", environment(me) );
	if (ob=present("fire", me))
		destruct(ob);
	delete("exits");
}


