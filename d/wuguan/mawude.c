int recognize_apprentice(object ob)
{       if (ob->query_skill("literate", 1) <= 20)
        {       ob->set_temp("mark/Öì", 1);
                return 1;
        }
        else
        {       ob->delete_temp("mark/Öì", 1);
                return 1;
        }
}
