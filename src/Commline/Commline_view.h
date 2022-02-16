#ifndef COMMLINE_VEW_H
#define COMMLINE_VIEW_H

#include <memory>

#include "Commline_model.h"

class Commline_view
{
	public:
		Commline_view(const std::shared_ptr<Commline_model>& model);

		std::string send_formatted(const std::string& account) const;

	private:
		std::shared_ptr<Commline_model> model_ptr;
};

#endif
