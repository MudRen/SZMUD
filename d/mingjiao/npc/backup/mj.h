// Code of ShenZhou
void unconcious()
{
       object ob = this_object();
       object cake;

        message_vision("\nͻȻ��ֻ��$N�ͳ�һ���ձ��̽����\n",
                ob);
       if (cake = present("shaobing",ob)) destruct(cake);
//     ob->die();
       ob->disable_player(" <���Բ���>");
        ob->set("jing", 0);
        ob->set("qi", 0);
        COMBAT_D->announce(ob, "unconcious");

        call_out("revive", random(100 - query("con")) + 30);

}

