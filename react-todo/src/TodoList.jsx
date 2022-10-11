import React from "react";

const TodoList = (props) => {
	return (
		<div
			style={{
				display: "flex",
				flexDirection: "row",
				justifyContent: "center",
				alignItems: "center",
			}}
			key={props.id}
		>
			<i
				className="fa fa-times"
				aria-hidden="true"
				id="fatime"
				onClick={() => {
					props.onSelect(props.id);
				}}
				style={{
					color: "crimson",
					paddingRight: "20px",
					fontSize: "30px",
				}}
			/>
			<li
				style={{
					listStyle: "none",
					fontSize: "30px",
					fontFamily: "monospace",
					color: "black",
				}}
			>
				{props.text}
			</li>
		</div>
	);
};

export default TodoList;